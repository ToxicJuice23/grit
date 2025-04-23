#!/bin/sh
snr_file() {
    # $1 = project name
    # $2 = file path
    upper=$(echo "$1" | tr '[:lower:]' '[:upper:]')
    sed -i -e "s/example/$1/g" ./$2.c
    sed -i -e "s/example/$1/g" ./$2.h
    sed -i -e "s/EXAMPLE/$upper/g" ./$2.c
    sed -i -e "s/EXAMPLE/$upper/g" ./$2.h
}

set -e

if [ $# -eq 0 ]; then
    echo "No argument was supplied."
    printf "Usage:\n./name-project.sh [{new name}|reset]\n"
    echo "Terminating script."
    exit 1
fi

if [ $1 = "reset" ]; then
    echo "Are you sure you want to reset your project?"
    read -p "y/n?: " ans
    if [ $ans = "y" ] || [ $ans = "Y" ] || [ $ans = "yes" ] || [ $ans = "YES" ]; then
        echo "Reseting now."
        rm -r ./*
        git fetch
        git reset --hard
        git pull https://github.com/ToxicJuice23/grit
        echo "Reset complete."
        exit 0
    fi
    echo "Reset was aborted by user."
    echo "Exiting now."
    exit 1
fi

./build.sh clean
sed -i -e "s/example/$1/g" build.sh

upper=$(echo "$1" | tr '[:lower:]' '[:upper:]')
echo $upper

mv ./src/example.c ./src/$1.c
mv ./src/example.h ./src/$1.h

snr_file $1 src/$1
snr_file $1 tests/test
sed -i -e "s/example/$1/g" ./src/main.c
sed -i -e "s/EXAMPLE/$upper/g" ./src/main.c