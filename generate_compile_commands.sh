#! /bin/bash

cd "$(dirname $0)"

CC="$(which cc)"

directory="$(pwd)"
command="${CC} -I/include -I/$(pwd)/include -I/$(pwd)/graphics -o build/main.o -c $(pwd)/source/main.c"
file="$(pwd)/source/main.c"

echo -n "[{\"directory\":\"${directory}\",\"command\":\"${command}\",\"file\":\"${file}\"}]" > compile_commands.json

cd -
