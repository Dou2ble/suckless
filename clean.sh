#!/bin/bash

for dir in */; do
    if [ -d "$dir" ]; then
        cd "$dir" || exit 1
	make clean
        cd .. || exit 1
    fi
done

