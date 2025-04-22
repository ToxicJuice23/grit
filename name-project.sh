#!/bin/sh
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
        exit 0
    fi
    echo "Reset was aborted by user."
    echo "Exiting now."
    exit 0    
fi

./build.sh clean
sed -i -e "s/example/$1/g" build.sh


upper=$(echo "$1" | tr '[:lower:]' '[:upper:]')

echo $upper

mv ./src/example.c ./src/$1.c
mv ./src/example.h ./src/$1.h

sed -i -e "s/example/$1/g" ./src/$1.c
sed -i -e "s/example/$1/g" ./src/$1.h
sed -i -e "s/EXAMPLE/$upper/g" ./src/$1.c
sed -i -e "s/EXAMPLE/$upper/g" ./src/$1.h
sed -i -e "s/example/$1/g" ./tests/test.c
sed -i -e "s/example/$1/g" ./tests/test.h
sed -i -e "s/EXAMPLE/$upper/g" ./tests/test.c
sed -i -e "s/EXAMPLE/$upper/g" ./tests/test.h