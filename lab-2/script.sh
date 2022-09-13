#!/bin/bash

# Пути к файлам, в которых:
os_info_path="./dir_script/os_info.txt"  # будут записаны данные об ос пользователя вида A=B
pc_info_path="./dir_script/pc_info.txt"  # будут записаны названия полей, заполняемых в скрипте
proc_info_path="./dir_script/processed_data.txt" # будут записаны строки из $pc_info_path, не начинающиеся с цифры
output_path="./res.txt" # будет записан результат выполнения программы

# создание/очистка выходного файла
touch $output_path
>$output_path

os_info=$(cat "/etc/lsb-release")  # данные об ос
printf "$os_info" >$os_info_path

fields_to_complete=$(cat $pc_info_path | grep "^[^0-9]")
printf "$fields_to_complete" >$proc_info_path

# разделение строк вида A=B на (A B)
prop_names=("Linux\n")
while read -r line; do
  mapfile -td \= fields <<<"$line"
  prop_names+=("${fields[1]}")
done <"$os_info_path"

i=0
while read -r line; do
  # есть данные только о первых 4 полях, поэтому выходим при $i > 4
  if [[ $i -eq 4 ]]; then
    break
  fi
  name="$line"
  printf "$name ${prop_names[i]}" >>$output_path
  ((i += 1))
done <"$proc_info_path"

rm $os_info_path
rm $proc_info_path

explorer.exe .
