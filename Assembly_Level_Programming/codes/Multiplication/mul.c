




MOV AX, 6
MOV BX, 4
MUL BX
HLT








/*
 
 
 
 Explanation:
1. MOV AX, 6 — AX contains 6.
2. MOV BX, 4 — BX contains 4.
3. MUL BX — Multiply AX by BX.
4. The 16-bit result is stored in DX:AX (the combined register pair).
Result: AX = 24, DX = 0
For this example, the result fits in AX.
 
 
 
 
 
 
 */
