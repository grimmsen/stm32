#!/bin/bash

if [ -z $1 ]; then
  echo "Usage: bin/createproject <projectname>"
  exit 1;
fi

if [ -d projects/$1 ]; then
  echo "project exists ..."
  exit 1
fi

mkdir -p projects/$1

echo H4sIAAAAAAAAA31RsW6DMBSc66+wlAwhqiFtlqpSpkaVMkQdiNRulXkY8ppnOwLTkr/vA5omZShCcL4zd9yzzz4MhFqu5GQycdoafsVexnHCdxOQ6gTIw2HElUf0I8q0AV2IvchNgc50lmqd7rbL++e7xdv7di3QATX5oGyGT5+26SZNNoMwYtfmE8Ek6S45u7TjnSJ4T7DX6NhTV1Y574wyOkMlAJibzn53RCUA/1vWlF1+KYQmehQ30xlAJJX/25+NuIZuKBBmdbesQ85QKmDPn4YRw3OnqKfZnL0sHJsV+CqYVtklr8O+sdl1AFzlotWliQ0V/4R2SFehQOLpqVe6VbthUoTuEFPO4X44yKhzvnRmFvzxJNWLzNDp6nQVNyCmhQAy2vEwKitVIee9PO8kfnohCtL1nuU6qB7KrwqDuRjIRfuw6C8hvgGvutHZUQIAAA== | base64 -d | gzip -d | sed -s "s/###name###/$1/g" > projects/$1/Makefile

echo "H4sIAAAAAAAAA4WOT0/CQBDF7/0UE7gsgdA/HDwIXtQACVoONB43TXdKB7e7TXcBjeG7u23RVD04ySQzb/f95g1JZfIoEObGClJ2Wtx5w55WzqI8DN5+yIOjJWn8TOrsdVoM/jzsK9KN7jkelCkpdtIkRvDhAbQmbtByUyEKdhONbp3cWDgpsjyVkrWS74NAiRYBT1i/24LUHtLcYg1uNiBJIaRKgLFpbZ2huaaVzvNF8I2sSPFSC2TL7Tq+n4SzSTPwp/jhkcfJbpvs2lvngiSysIsIkOsa2NHxZhG3cHA8OMAcwqCtZOPW8dh9Bs6f462LC5fWRznrAiyCL1Qvx7km2wuyiV/a2011rrBbL4DS4L/+1Xq5+gUIrgCv6YvnfQKAIYu03QEAAA==" | base64 -d | gzip -d > projects/$1/$1.c
