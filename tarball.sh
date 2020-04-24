#!/bin/sh

echo "#####################"
echo "# TARBALL GENERATOR #"
echo "#####################"

echo -n "titi: "
read titi
echo -n "toto: "
read toto
echo

tarball="${titi}_${toto}.tar.gz"

echo "cleaning..."
rm -rf $tarball
make -C NUAGES_SRC clean
echo

echo "${tarball}:"
tar -cvf "$tarball" "NUAGES_SRC" "IMAGES"
