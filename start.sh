#!/bin/bash
echo "Script started"
if [[ "$@" -lt 3 ]]
then
  echo "Missing arguments"
  exit 1
fi
file=$"$@"
let "num=$@-2"
#exicutable keys start
key_help=0
key_add=0
key_del=0
key_show=0
key_show_alldb=0
key_del_alldb=0
key_create=0

#exicutable keys end
#__________________________
for (( i=1; i <= $num; i++ ))
do
  case $1 in
    "-h" | "--help" ) key_help=1 ;;
    "-a" | "--add" ) key_add=1 ;;
    "-q" | "--request" ) key_show=1 ;;
    "-sa" | "--show_all" ) key_show_alldb=1 ;;
    "-da" | "--delete_all" ) key_del_alldb=1 ;;
    "-d" | "--delete" ) key_del=1 ;;
    "-c" | "--create" ) key_create=1 ;;
  esac
  shift
done

param="$1"
file_path="$2"
if [[ $key_help -eq 1 ]]
then
  cat help.txt
  exit 0
fi

if [[  ]]