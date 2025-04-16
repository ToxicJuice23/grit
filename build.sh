#!/bin/sh
if [ -d "./src" ] && [ -d "./tests" ]; then
	echo "Building in correct dir"
	echo "Proceeding.."
else
	echo "Script is in wrong directory"
	echo "Please run in root dir of project"
	echo "Build failed."
	exit 1
fi

mkdir -p build
main="src/main.c"
src="src/example.c"
test_src="tests/test.c"
target="build/example"
obj="build/example.o"
test_target="build/test"
debug="build/example_debug"
CFLAGS="-O2 -Wall -Wextra"
LDFLAGS="-lm"
TESTFLAGS="-I./src"

if [ "$(gcc -dumpversion | cut -d. -f1)" -gt 11 ]; then
	echo "GCC version is greater than 11, proceeding.."
else
	echo "GCC version is 11 or lower, exiting.."
	echo "Build failed."
	exit 1
fi

if [ $1 = "build" ]; then
	gcc -o $target $main $src $CFLAGS $LDFLAGS
elif [ $1 = "debug" ]; then
	gcc -o $debug $main $src -Wall -Wextra -g $LDFLAGS
elif [ $1 = "clean" ]; then
	rm -rf build
elif [ $1 = "test" ]; then
	gcc -o $obj -c $src $CFLAGS $LDFLAGS -w
	gcc -o $test_target $test_src $obj $CFLAGS $LDFLAGS $TESTFLAGS -w
	./$test_target
	rm -f $test_target $obj
	exit 0
elif [ $1 = "run" ]; then
	echo "running"
	gcc -o $target $src $main $CFLAGS $LDFLAGS
	./$target
	exit 0
else
	gcc -o $target $src $main $CFLAGS $LDFLAGS
fi

echo "Build was successful!"