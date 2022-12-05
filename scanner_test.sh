#!/bin/bash

BIN="ial22"
filename_array=("graph_16_cell" "graph_antenna" "graph_antiprism" "graph_Chvatal" "graph_cross" "graph_Franklin" "graph_GoddardHenning" "graph_Grotzsch" "graph_Heawood" "graph_K3,3" "graph_K5" "graph_Lemke" "graph_Petersen" "graph_sun" "graph_Tilley")
#file_array=("$(cat input/graph_16_cell.graph)" "$(cat input/graph_antenna.graph)" "$(cat input/graph_antiprism.graph)" "$(cat input/graph_Chvatal.graph)" "$(cat input/graph_cross.graph)" "$(cat input/graph_Franklin.graph)" "$(cat input/graph_GoddardHenning.graph)" "$(cat input/graph_Grotzsch.graph)" "$(cat input/graph_Heawood.graph)")

#echo "\nTest output differences:"
#echo "Test ${filename_array[$j]}"
#./ial22 scanner <"input/${filename_array[j]}.graph" >"${filename_array[j]}_current.output"
#diff -s -U 5 "${filename_array[j]}_current.output" "test/scanner/${filename_array[j]}_reference.output"
#rm "${filename_array[j]}_current.output"
#exit 0


for (( j=0; j<${#filename_array[@]}; j++ ))
do
  echo "Test output differences:"
  echo "Test ${filename_array[$j]}"
  ./ial22 scanner <"input/${filename_array[j]}.graph" >"${filename_array[j]}_current.output"
  diff -s -U 5 "${filename_array[j]}_current.output" "test/scanner/${filename_array[j]}_reference.output"
  rm "${filename_array[j]}_current.output"
done

exit 0
