#!/bin/bash
# @file graph_load.sh
# @project IAL Náhradní projekt - 05. Rovinnost grafu
# @author Vladimir Meciar (xmecia00)
# @brief This script executes project binary with input graph from folder /input
# @changes 7.12.2022

filename_array=("graph_16_cell" "graph_antenna" "graph_antiprism" "graph_Chvatal" "graph_cross" "graph_Franklin" "graph_GoddardHenning" "graph_Grotzsch" "graph_Heawood" "graph_K3,3" "graph_K5" "graph_Lemke" "graph_Petersen" "graph_sun" "graph_Tilley")

# Iterate through each one and compare results
for (( j=0; j<${#filename_array[@]}; j++ ))
do
  ./ial22 <"input/${filename_array[j]}.graph" >"${filename_array[j]}_current.output"
done

exit 0