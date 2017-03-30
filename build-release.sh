if [$CC == ""]; then
	CC=gcc
fi

if [ ! -d "./build" ]; then
	mkdir build
fi

for file in $(find ./src -name '*.c'); do
	fname=$(basename $file)
	$CC -std=c11 -pedantic -Wall -Wextra -O3 -I ./src -o "build/${fname%".c"}.out" $file
done

