#!/bin/bash

BRANCH="$1/index.html"
FILE=$(cat index.html)

if [[ $FILE = *$BRANCH* ]]
then
	echo "Link exists"
else
	tac index.html | sed '0,/<\/tr>/{s/<\/tr>/<\/tr>\n      <td class="coverFile"><a href="test2\/index.html">test2<\/a><\/td>\n    <tr>\n    <\/tr>/}' | tac > index2.html
	rm index.html
	mv index2.html index.html
fi




    