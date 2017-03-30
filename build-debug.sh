if [$CC == ""]; then
	CC=gcc
fi

if [ ! -d "./build" ]; then
	mkdir build
fi

for file in $(find ./src -name '*.c'); do
	fname=$(basename $file)
	$CC -std=c11 -pedantic -Wall -Wextra -O0 -ggdb -fsanitize=address -I ./src -o "build/${fname%".c"}-d.out" $file
done

