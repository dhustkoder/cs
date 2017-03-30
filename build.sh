#!/bin/bash

BASEDIR=$(dirname $0)
SRC_DIR="${BASEDIR}/src"
OUTPUT_DIR="${BASEDIR}/build"

if ["$CC" == ""]; then
	CC=gcc
fi

if [ ! -d $OUTPUT_DIR ]; then
	mkdir $OUTPUT_DIR
fi


compile ()
{
	mode=$1
	cargs=$2

	echo "Building in ${mode} mode"

	for file in $(find $SRC_DIR -name '*.c'); do
		fname=$(basename $file)
		outname="${OUTPUT_DIR}/${fname%".c"}-${mode}.out"
		echo "${file}: ${outname}"
		$CC -std=c11 -Wall -Wextra -pedantic $cargs -I $SRC_DIR -o $outname $file
	done
}


if [[ "${1}" == "debug" || "${1}" == "" ]]; then
	compile "debug" "-O0 -ggdb -fsanitize=address"
elif [[ "${1}" == "release" ]]; then
	compile "release" "-O3"
else
	echo "Usage: ${0} [mode]"
	echo "mode: debug, release"
fi

