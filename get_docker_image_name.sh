#!/bin/bash

CI_COMMIT_TAG=$1
CI_COMMIT_REF_NAME=$2

echo $CI_COMMIT_TAG
echo $CI_COMMIT_REF_NAME

if [ -z "$1" ]
then
      echo "\$var is empty"
else
      echo "\$var is NOT empty"
fi
