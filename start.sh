#!/bin/bash
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
file_path="${!#}"
for (( i=1; i <= $#; i++ ))
do
  if [ "${1:0:1}" = "-" ]; then
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
  fi

done
param=$1

#Показать помощь
if [[ $key_help -eq 1 ]]
then
  cat help.txt
  exit 0
fi

if [[ ! -e "$file_path" && $key_create -eq 0 ]]; then
    echo "File does not exist. Do you want to create its?"
    read -p "y/n " a
    if [[ "$a" = "y" ]]; then
      key_create=1
    fi
fi

#Создание БД
if [[ $key_create -eq 1 ]]
then
  > "$file_path"
  echo "db succsesfully created"
  exit 0
fi

#удаление БД
if [[ $key_del_alldb -eq 1 ]]
then
  rm "$file_path" || exit 126
  echo "db succsesfully deleted"
  exit 0
fi

#показать БД
if [[ "$key_show_alldb" -eq 1 ]]
then
  ./cmake-build-debug/kp6 s "$file_path" || exit 126
  exit 0
fi

if [[ "$#" -lt 2 ]]
then
  echo "Missing arguments"
  exit 1
fi

#request
if [[ "$key_show" -eq 1 ]]
then
  ./cmake-build-debug/kp6 q "$param" "$file_path" || exit 1
fi

#добавление
if [[ "$key_add" -eq 1 ]]; then
  if [[ "$#" -eq 9 ]]; then
    param1=$1
    param2=$2
    param3=$3
    param4=$4
    param5=$5
    param6=$6
    param7=$7
    param8=$8

      ./cmake-build-debug/kp6 a "$param1" "$param2" "$param3" "$param4" "$param5" "$param6" "$param7" "$param8" "$file_path" || exit 1
  else
    echo "sm wrong with parameters"
    exit 1
  fi
fi
#удалить элемент
if [ "$key_del" -eq 1 ]; then
    ./cmake-build-debug/kp6 d "$param" "$file_path" || exit 1
fi

#сделать мое задание
if [ "$key_MakeMyTask" -eq 1 ]; then
    ./cmake-build-debug/kp6 m "$param" "$file_path" || exit 1
fi