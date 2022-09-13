#!/bin/bash

os_info_path="./dir_script/os_info.txt"
pc_info_path="./dir_script/pc_info.txt"
proc_info_path="./dir_script/processed_data.txt"
output_path="./res.txt"

touch $output_path
>$output_path

os_info=$(cat "/etc/lsb-release")
printf "$os_info" >$os_info_path

fields_to_complete=$(cat $pc_info_path | grep "^[^0-9]")
printf "$fields_to_complete" >$proc_info_path

prop_names=("Linux\n")
while read -r line; do
  mapfile -td \= fields <<<"$line"
  prop_names+=("${fields[1]}")
done <"$os_info_path"

i=0
while read -r line; do
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
