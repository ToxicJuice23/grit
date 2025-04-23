#!/bin/sh
compile() {
    gcc -o "$1" $main $src $CFLAGS $LDFLAGS
}

set -e

if [ $1 = "help" ]; then
	printf "%s [option]\n\tbuild: default\n\tdebug: build a debuggable executable\n\tclean: remove all build files\n\ttest: run the tests in test.c (see README.md)\n\trun: build, run, cleanup\n" $0
	exit 0
fi

if [ -d "./src" ] && [ -d "./tests" ]; then
	echo "Building in correct dir"
	echo "Proceeding.."
else
	echo "Script is in wrong directory"
	echo "Please run in root dir of project"
	echo "Build failed."
	exit 1
fi

main="src/main.c"
build_dir="build"
src="src/example.c"
test_src="tests/test.c"
target="${build_dir}/example"
obj="${build_dir}/example.o"
test_target="${build_dir}/test"
debug="${build_dir}/example_debug"
CFLAGS="-O2 -Wall -Wextra"
LDFLAGS="-lm"
TESTFLAGS="-I./src"
mkdir -p "${build_dir}"

if [ "$(gcc -dumpversion | cut -d. -f1)" -gt 11 ]; then
	echo "GCC version is greater than 11, proceeding.."
else
	echo "GCC version is 11 or lower, exiting.."
	echo "Build failed."
	exit 1
fi

if [ "$1" = "build" ]; then
	compile $target
elif [ "$1" = "debug" ]; then
	gcc -o $debug $main $src -Wall -Wextra -g $LDFLAGS
elif [ "$1" = "clean" ]; then
	rm -rf "${build_dir}"
elif [ "$1" = "test" ]; then
	gcc -o $obj -c $src $CFLAGS $LDFLAGS -w
	gcc -o $test_target $test_src $obj $LDFLAGS $TESTFLAGS
	./$test_target
	rm -f $test_target $obj
	rmdir "${build_dir}"
	exit 0
elif [ "$1" = "run" ]; then
	echo "running"
	compile $target
	./$target
	exit 0
else
	compile $target
fi

echo "Build was successful!"