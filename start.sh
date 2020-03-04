#!/bin/bash
echo "Script started"

let "num=$#-2"
#exicutable keys start
key_help=0
key_add=0
key_del=0
key_show=0
key_show_alldb=0
key_del_alldb=0
key_create=0
key_MakeMyTask=0
#exicutable keys end
#__________________________
echo $#
for (( i=1; i <= $num; i++ ))
do
  if [ "$1" = "-*" ]; then

  fi
  case "$1" in
    "-h" | "--help" ) key_help=1;;
    "-a" | "--add" ) key_add=1 ;;
    "-q" | "--request" ) key_show=1 ;;
    "-sa" | "--show_all" ) key_show_alldb=1 ;;
    "-da" | "--delete_all" ) key_del_alldb=1 ;;
    "-d" | "--delete" ) key_del=1 ;;
    "-c" | "--create" ) key_create=1 ;;
    "-m" | "--make" ) key_MakeMyTask=1 ;;
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

if [[ $key_create -eq 1 ]]
then
  touch "$file_path"
  exit 0
fi

if [[ $key_del_alldb -eq 1 ]]
then
  rm "$file_path" || exit 126
  exit 0
fi

if [[ "$key_show_alldb" -eq 1 ]]
then
  cat "$file_path" || exit 126
  exit 0
fi

if [[ "$#" -lt 2 ]]
then
  echo "Missing arguments"
  exit 1
fi

if [[ "$key_show" -eq 1 ]]
then
  ./cmake-build-debug/kp6 q || exit 1
fi

if [[ "$key_add" -eq 1 ]]; then
    ./cmake-build-debug/kp6 a || exit 1
fi

if [ "$key_del" -eq 1 ]; then
    ./cmake-build-debug/kp6 d || exit 1
fi

if [ "$key_MakeMyTask" -eq 1 ]; then
    ./cmake-build-debug/kp6 m || exit 1
fi