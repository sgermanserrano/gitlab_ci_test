#!/bin/bash

CI_COMMIT_TAG=$1
CI_COMMIT_REF_NAME=$2

echo $CI_COMMIT_TAG
echo $CI_COMMIT_REF_NAME

if [ -z "$CI_COMMIT_TAG" ]
then
      
      echo "$CI_COMMIT_TAG"
else
      echo "${CI_COMMIT_REF_NAME:8:10}"
fi
