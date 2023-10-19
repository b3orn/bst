target := bst

include_dir := include
src_dir := src
build_dir := build
tests_dir := tests


CCFLAGS := \
	-Wall \
	-Wextra \
	-Weverything \
	-Wno-poison-system-directories \
	-Wno-padded \
	-Wno-documentation \
	-Wno-documentation-unknown-command \
	-O0 \
	-I$(include_dir)

LDFLAGS :=
LDLIBS :=

ifndef release
	CCFLAGS += -g -D BST_DEBUG_ENABLED
endif

os_arch := $(shell uname -m)
os_name := $(shell uname -s)

ifeq ($(os_arch),x86_64)
	target_arch := amd64
	CCFLAGS += -D BST_ARCH_AMD64
else ifeq ($(os_arch),aarch64)
	target_arch := arm64
	CCFLAGS += -D BST_ARCH_ARM64
else ifeq ($(os_arch),arm64)
	target_arch := arm64
	CCFLAGS += -D BST_ARCH_ARM64
else
$(error "Unsupported architecture ${os_arch}")
endif

ifeq ($(os_name),Darwin)
	target_os := macos
	CC := clang
	CCFLAGS += -std=c11 -Weverything -D BST_OS_POSIX -D BST_OS_MACOS
	LDFLAGS += -dynamiclib -arch $(os_arch)
	LDLIBS += -pthread
	LIB_EXT := dylib
else ifeq ($(os_name),Linux)
	target_os := linux
	CC := gcc
	CCFLAGS += -std=gnu11 -D BST_OS_POSIX -D BST_OS_LINUX
	LDFLAGS += -shared -march=$(os_arch)
	LDLIBS += -lm -ldl -pthread
	LIB_EXT := so
else
$(error "Unsupported operating system ${OS_NAME}")
endif

out_dir := $(build_dir)/$(target_os)-$(target_arch)

header_files := $(wildcard $(include_dir)/$(target)/*.h)
src_files := $(wildcard $(src_dir)/*.c)
obj_files := $(patsubst $(src_dir)/%.c,$(out_dir)/%.o,$(src_files))

test_src_files := $(wildcard $(tests_dir)/*.c)
test_bin_files := $(patsubst $(tests_dir)/%.c,$(out_dir)/tests/%,$(test_src_files))

shared_target := $(out_dir)/lib/lib$(target).$(LIB_EXT)
static_target := $(out_dir)/lib/lib$(target).a


.PHONY: all clean

all: $(shared_target) $(static_target)

tests: $(test_bin_files)

clean:
	-rm -r $(out_dir)


$(shared_target): $(obj_files)
	mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $(LIBFLAGS) -o $@ $^ $(LDLIBS)


$(static_target): $(obj_files)
	mkdir -p $(dir $@)
	ar rcs $@ $^


$(out_dir)/%.o: $(src_dir)/%.c $(header_files)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -o $@ -c $<


$(out_dir)/tests/%: $(tests_dir)/%.c $(header_files) $(shared_target)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) $(LIBFLAGS) -o $@ $< $(LDLIBS) -l$(target) -L$(out_dir)/lib
