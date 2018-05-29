#!/bin/bash

hdir='.hooks'
for f in $(find $hdir -type f); do
  name=$(basename $f)
  echo -n "Linking: $name ... "
  ln -s -f ../../$hdir/$name .git/hooks/$name && echo "done"
done
