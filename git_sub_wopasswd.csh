#! /bin/csh -f
#source this file and type in username & password in a git push, then 
#you don't have to type in username & password when doing git push afterwards.

git config credential.helper store

