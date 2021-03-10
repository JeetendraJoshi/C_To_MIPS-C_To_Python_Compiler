# langproc-2019-cw-Flexpired-and-Parsed-away
# MIPS-Simulator

This is a C++ implementation of a C to MIPS Compiler and C to Python Translator as part of a project done in pairs for the Electronic and Information Engineering 2nd Year course at Imperial College London. 
The compiler and translator is built according to the following specfication https://github.com/JeetendraJoshi/langproc-2019-cw. 
An ideal compiler and translator would pass all tests in the provided testbench and any other testbench containing only the instructions that have been implemented.

To construct the Python translator and MIPS Compiler use command:
`make bin/c_compiler`

To run the Python Translator use command:
`bin/c_compiler --translate [source-file.c] -o [dest-file.py]`

To run the MIPS Compiler use command:
`bin/c_compiler -S [source-file.c] -o [dest-file.s]`

Both the compiler and translator were implemented from scratch without the use of the pre-existing skeleton code. 

# Acknowledgements

Freddie Mccallum for collaborating on the implementation of both the MIPS Compiler and Python Translator in addition to testing of the compiler and translator.

Dr. John Wickerson for contiuous support and guidance throughout the project.
