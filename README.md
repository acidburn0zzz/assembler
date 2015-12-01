# Assembler
Small assembly-like language compiler
# About language
The instruction set is forked from arm instruction set, but it is abbrivated a some.
It only has 17 instructions, and, as in arm condition language, every instruction appeal must be accompanied by
a condition for its executing.

# Syntax
The common syntax is:
[condition] [instruction] [arg0] [arg1] [arg2].
For giving argument as a register write 'r' after the number of it, for giving ram write '$' or '@' or 'm' and 
for giving a number, place there '#'.
There are 32 registers: from r00 to r31

The only 17 instructions:
- mov [mem_dest] [value]
- push [value]
- pop [mem_dest]
- add [mem_dest] [value] [value]
- sub [mem_dest] [value] [value]
- mul [mem_dest] [value] [value]
- seg [mem_dest] [value] [value]
- and [mem_dest] [value] [value]
- or  [mem_dest] [value] [value]
- xor [mem_dest] [value] [value]
- not [mem_dest] [value]
- compl [mem_dest] [value]
- swi [value]
- nop 
- inc [mem_dest]
- dec [mem_dest]
- cmp [value] [value]

And the only 7 conditions:
- al - Execute always
- eq - Only if compare flag set to equals
- ne - Only if compare flag is not set to equals
- ae - Only if compare flag is set to above or equals
- le - Only if compare flag set to less or equals
- av - Only if compare flag set to above
- ls - Only if compare flag set to less
