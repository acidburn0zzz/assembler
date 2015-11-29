al push #45 
al pop r00
al cmp r00, #45 ; Compare r00 to 45
eq push $33
eq pop r05
al add r00, r00, r05
eq cmp r00, r05;
eq nop
