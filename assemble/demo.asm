al push #45
al pop r00
al mov r01, @50
al sub r01, r01, #5
al cmp r00, r01
eq mov r02, $5
eq swi r02 ;Out data from r01
al nop

