if [[ -d "./src" && -d "./tests" ]]; then
	echo "Building in correct dir"
	echo "Proceeding.."
else
	echo "Script is in wrong directory"
	echo "Please run in root dir of project"
	exit 1
fi

mkdir -p build
src="src/main.c"
target="build/main"
debug="build/main_debug"
CFLAGS="-O2 -Wall -Wextra"
LDFLAGS="-lm"

if [ "$(gcc -dumpversion | cut -d. -f1)" -gt 11 ]; then
	echo "GCC version is greater than 11, proceeding.."
else
	echo "GCC version is 11 or lower, exiting.."
	exit 1
fi

if [ $0 = "build" ]; then
	gcc -o $target $src $CFLAGS $LDFLAGS
elif [ $0 = "debug" ]; then
	gcc -o $target $debug -Wall -Wextra -g $LDFLAGS
elif [ $0 = "clean" ]; then
	rm -r build
else
	gcc -o $target $src $CFLAGS $LDFLAGS
fi
