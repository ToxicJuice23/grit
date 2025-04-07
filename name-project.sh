#!/bin/sh
if [ $# -eq 0 ]; then
    echo "No argument was supplied."
    echo "Terminating script."
    exit 1
fi

if [ $1 = "reset" ]; then
    echo "Are you sure you want to reset your project?"
    read -p "y/n?: " ans
    if [ $ans = "y" ] || [ $ans = "Y" ] || [ $ans = "yes" ] || [ $ans = "YES" ]; then
        echo "Reseting now."
        git fetch origin
        git reset --hard origin/master
        exit 0
    fi
    echo "Reset was aborted by user."
    echo "Exiting now."
    exit 0    
fi

./build.sh clean
sed -i -e "s/example/$1/g" build.sh

#!/bin/bash
upper=$(echo "$1" | tr '[:lower:]' '[:upper:]')
#!/bin/sh
echo $upper

mv ./src/example.c ./src/$1.c
mv ./src/example.h ./src/$1.h

sed -i -e "s/example/$1/g" ./src/$1.c
sed -i -e "s/example/$1/g" ./src/$1.h
sed -i -e "s/EXAMPLE/$upper/g" ./src/$1.c // todo make $1 upper yo
sed -i -e "s/EXAMPLE/$upper/g" ./src/$1.h