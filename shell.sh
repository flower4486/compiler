#!/bin/bash

TEST_DIR=./test
OUTPUT_DIR=./output 
mkdir -p $OUTPUT_DIR

count=1

for i in $(ls $TEST_DIR/*.sy); do

  filename=$(basename $i)

  # 生成按编号的输出文件名
  output_file=test_${count}.s

  # 编译
  ./src/mind -l 5 $TEST_DIR/$filename -o $OUTPUT_DIR/$output_file

  if [ $? -ne 0 ]; then
    echo "Compilation failed for file: $filename"
    continue
  fi

  # 编译可执行文件
  riscv64-unknown-elf-gcc $OUTPUT_DIR/$output_file -o $OUTPUT_DIR/test

  # 运行测试
  qemu-riscv64 $OUTPUT_DIR/test
  echo $?
  /usr/bin/time -f "%e" qemu-riscv64 $OUTPUT_DIR/test 
  # if [ $? -ne 0 ]; then
  #   #echo "Execution failed for file: $filename"
  #   echo $?
  # else
  #   /usr/bin/time -f "%e" qemu-riscv64 $OUTPUT_DIR/test 
  # fi

  count=$((count+1)) 

done