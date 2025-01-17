# Simple-Integer-Machine:
## How to Run:
  To run the processor you should first compile the files that compose the processors by typing in this command:
  ```
    g++ InstructionFactory.h Instructions.h sizes.h Exceptions.h Parser.h Processor.h main.cpp -o out
  ```
  Now you can run the processor, by typing in the command line:
  ```
    ./out argv[1]

    argv[1]: DIRECTORY/FILENAME.txt; the location and name of the file containing the code that you want the processor to run.
  ```
 
  You can use the already existing sample programs [Sample Programs](./Sample_Programs). Example:
  ```
    ./out ./Sample_Programs/sample3.txt
  ```

  or you can add your own example program and run it using the same command.

## Processor and class construction:
### Instruction Representation:
  There is a parent abstract Instruction class. It is used to encapsulate all instructions supported by the processor 

  There are three abstract children to this class and one other child:

#### Instruction3Param:
  This is a parent abstract class for all instructions that has 3 parameters:

##### ADD, MUL, JMP0, LE Instruction:
  Takes references to memory addresses or Immediates and performs the corresponding functionality on them. Find more in `Supported Instructions` section of the README

#### Instruction2Param:
  This is a parent abstract class for all instructions that has 2 parameters:

##### NEG, JMP, ASS Instruction:
  Takes references to memory addresses or Immediates and performs the corresponding functionality on them. Find more in `Supported Instructions` section of the README

#### Instruction1Param:
  This is a parent abstract class for all instructions that has 1 parameter:

##### READ, WRITE Instruction:
  Takes references to memory addresses or Immediates and performs the corresponding functionality on them. Find more in `Supported Instructions` section of the README

#### HALT:
  This is a child class for Instruction that is used to throw the program terminating exception.

### Parser:
  Reads a program file and extracts the instruction and parameters separately then fills the instruction memory of the processor by calling the InstructionFactory to create an instruction of the proper time.

### InstructionFactory:
  Takes an InstructionType and parameters; validates the format of the parameters. Finally create a new instruction with the given information and returns a pointer to it.

### Exceptions:
  The exception classes include:
- HALTException: for program termination.
- InsufficientParameters: if the number of parameters for an instruction is not correct.
- InvalidInstruction: if the instruction is not supported by the processors
- InvalidParameter: if the parameter for a given instruction is malformed.
- OutOfDataMemoryBounds: if the user tried to access a data memory address that is out of bounds
- OutOfInstructionMemoryBounds: if the user tried to access an instruction memory address that is out of bounds
- ParameterShouldBeAddress: if a parameter was expected to be a data memory address but was received as an immediate
- OverFlow: for operation overflow while performing instructions
- BadFile: if the program file doesn't exist, was written mistakenly or was corrupt
- Memory Allocation Exceptions: new and delete operators throw exceptions of type exception if memory freeing or allocation failed. Those are received by the catch block. Therefore, no need to implement a class for them as they already exist in the STL. 

### Includes:
- Exceptions.h: to encapsulate all exception classes
- Instructions.h: to encapsulate all instruction classes
- sizes.h: to encapsulate all definition of sizes Instruction Memory and Data Memory

### Processsor:
  This class encapsulates all other classes:
- It has an instruction memory.
- It has a data memory.
- It has a program counter.
- It loads the program from a given file using the Parser and stores it in the instruction memory.
- It runs the instruction memory starting from position 0.
- It handles all exceptions by printing their values and rethrowing them for the main program in case further analysis is needed.
## Sample Programs:
### Required Formatting:
  The program file should have one instruction per line with an empty line at the end of the file.
  Each instruction should be as follows
  ```
    InstructionName Parameter1,Parameter2,Parameter3

    InstructionName: Should be captilized form of the instruction name as stated in the handout: ADD, JMP, 
    Parameter1: should be the first parameter
    Parameter2: should be the second parameter
    Parameter3: should be the third parameter
  ``` 
  Parameters could be:
  ```
    Memory Reference: $Address.         i.e: $1 is data memory address 1
    Immediate:  Immediate.              i.e: 1 is the value 1
  ```
  Samples:
  ```
    ADD $1,2,$100

    This would add the value in memory address 1 to the Immediate 2 and then store the result in memory address 100
  ```
### Sample1.txt:
    Performs all instructions in a random flow.

### Sample2.txt:
  Sorting 3 numbers
  This program runs as follows:
  - Read 3 values from the user.

  - Sort them ascendingly.
    
  - Print the sorted values.

    Used instruction types: READ, LE, JMP0, JMP, ASS, WRITE, HALT

### Sample3.txt:
  Calculating the factorial of a given number
  This program runs as follows:
  - Read 3 values from the user.

  - Sort them ascendingly.
    
  - Print the factorial value.

    Used instruction types: READ, ASS, MUL, ADD, JMP0, JMP, WRITE, HALT

### Sample4.txt:
  Receives an array of numbers and computes the sum.
  This program runs as follows:
  - Read the array size from the user from the user.

  - Read the values of the array from the user.

  - Add them while reading.
    
  - Print the sum.

    Used instruction types: READ, JMP0, JMP, ASS, ADD, WRITE, HALT

### Sample5.txt:
  Receives an array of numbers and computes the product of all elements.
  This program runs as follows:
  - Read the array size from the user from the user.

  - Read the values of the array from the user.

  - Multiply them while reading.
    
  - Print the product.

    Used instruction types: READ, JMP0, JMP, ASS, ADD, MUL, WRITE, HALT


### crash1.txt:
  Shows exception handling in case of missing parameters.

### crash2.txt:
  Shows exception handling in case of invalid instruction name.

### crash3.txt:
  Shows exception handling in case of invalid parameters.

### crash4.txt:
  Shows exception handling in case of using an output that is not an address.

### crash5.txt:
  Shows exception handling in case of overflow.

### crash6.txt:
  Shows exception handling in case of data memory out of bounds.

### crash7.txt:
  Shows exception handling in case of jumping to instruction memory out of bounds.

### crash8.txt:
  Shows exception handling in case of jumping to instruction memory location that doesn't have an instruction.

## Supported Instructions:
- ADD: ADD in1,in2,out ; out =in1+in2 ; out must be an data memory address

- NEG: NEG in1,out ; out = - in1 ; out must be an data memory address

- MUL: MUL in1,in2,out ; out =in1*in2 ; out must be an data memory address

- JMP: JMP in1 ; jump to address in1 in the instruction memory; in1 must be within instruction memory bounds

- JMP0: JMP0 in1,in2 ; if(in1 == 0): jump to address in2 in the instruction memory; in2 must be within instruction memory bounds

- ASS: ASS in1,out ; out = in1 ; out must be an data memory address

- LE: LE in1,in2,out ; if(in1<=in2): out = 1 else out = 0 ; out must be an data memory address

- READ: READ in1 ; cin >> in1 ; in1 must be an data memory address

- WRITE: WRITE in1 ; cout << in1 ;