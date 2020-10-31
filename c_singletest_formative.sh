#!/bin/bash
dos2unix c_singletest_formative.sh  
if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="bin/c_compiler"
fi
 
have_compiler=0
if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}. Only checking C reference against python reference."
    have_compiler=1
fi

 
    # Compile the reference C version
#gcc temptest/test_program.c -o temptest/test_program.out
#./temptest/test_program.out
    # Run the reference C version
#REF_C_OUT=$?
#echo $REF_C_OUT
#echo "C output ^^"
   
    # Run the reference python version
    #python3 ${input_dir}/$base.py
    #REF_P_OUT=$?
if [[ ${have_compiler} -eq 0 ]] ; then       
        # Create the DUT python version by invoking the compiler with translation flags
    #mips-linux-gnu-gcc -c temptest/test_program_driver.c -o temptest/test_program_driver.o 
    #cat temptest/test_program.c | $compiler > temptest/test.s
   
    #mips-linux-gnu-gcc -static temptest/test_program.s temptest/test_program_driver.o -o temptest/test.elf 
    #qemu-mips temptest/test.elf

    $compiler -S temptest/test_program.c -o temptest/test_program.s
    mips-linux-gnu-gcc -mfp32 -o temptest/test_program.o -c temptest/test_program.s
    mips-linux-gnu-gcc -mfp32 -static -o temptest/test_program temptest/test_program.o temptest/test_program_driver.c
    qemu-mips temptest/test_program


    #GOT_P_OUT=$?
    echo $?
    echo "MIPS output ^^"
fi
    

#if [[ ${have_compiler} -ne 0 ]] ; then
#    echo "Fail, No C compiler/translator"
#fi
#if [[ $REF_C_OUT -ne $GOT_P_OUT ]] ; then
#    echo "Fail, Expected ${REF_C_OUT}, got ${GOT_P_OUT}"
#fi
#if [[ $REF_C_OUT -eq $GOT_P_OUT ]] ; then
#    echo "Pass"
#fi