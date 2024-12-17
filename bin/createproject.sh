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
cd projects/$1
ln -s ../../ld_vectors.ld .
cd -

echo H4sIAAAAAAAAA31RsW6DMBCd66+wlAwhqiFtlqpSpkaVMkQdiNRukTkOcHPYEZiW/H0PaJqEoRYyz+8d73Fnl3wi+Fqu5GQysbpEfoVOhmHET+MN1ZHRuC+0TQmreiQBOTiMOGy9sX5E5kfjQidSzIzFLk2t4912+fj6sPjYb9fCWKAmHZTN8OHLNt7E0WYQRuwavwxgFO+is0s7rhTeOYJCG8ueuiqVdRYV6sQoAcDcdPZXEeQA/G9Jk3f5uRCa6FncTWcAgVTudjRsxG3ohjyZpO6OtU8ZSgXs+dthwPDcU9DTbM5eJRybFbjKY6vKJZ990ZTJdQBc5ZpS5xgiZf+EdkhXPjPE01PvdK92w6TI2ENIKYe74Y6DzvnSM7Pgjiep3mRirK5OV3EDYloIINSWh1GVUmVy3svzTuLdCZGRrguWa696KL8r4/FiIBft06JfQvwAvxsQVGwCAAA= | base64 -d | gzip -d | sed -s "s/###name###/$1/g" > projects/$1/Makefile

echo "H4sIAAAAAAAAA4WOT0/CQBDF7/0UE7gsgdA/HDwIXtQACVoONB43TXdKB7e7TXcBjeG7u23RVD04ySQzb/f95g1JZfIoEObGClJ2Wtx5w55WzqI8DN5+yIOjJWn8TOrsdVoM/jzsK9KN7jkelCkpdtIkRvDhAbQmbtByUyEKdhONbp3cWDgpsjyVkrWS74NAiRYBT1i/24LUHtLcYg1uNiBJIaRKgLFpbZ2huaaVzvNF8I2sSPFSC2TL7Tq+n4SzSTPwp/jhkcfJbpvs2lvngiSysIsIkOsa2NHxZhG3cHA8OMAcwqCtZOPW8dh9Bs6f462LC5fWRznrAiyCL1Qvx7km2wuyiV/a2011rrBbL4DS4L/+1Xq5+gUIrgCv6YvnfQKAIYu03QEAAA==" | base64 -d | gzip -d > projects/$1/$1.c
