






MOV AX, 7
MOV BX, 2
MOV DX, 0
DIV BX
CMP DX, 0
JE EVEN
JMP ODD

EVEN:
    MOV CX, 0
    HLT

ODD:
    MOV CX, 1
    HLT













 Explanation:
1. MOV AX, 7 — Load the number 7.
2. MOV BX, 2 — Load the divisor 2.
3. MOV DX, 0 — Clear the upper half of the dividend.
4. DIV BX — Divide DX:AX by BX.
5. CMP DX, 0 — Check the remainder.
6. JE EVEN — Jump to EVEN if the remainder is zero.
7. Otherwise, jump to ODD.
Result:
- CX = 0 means even.
- CX = 1 means odd.
For input 7, the result is CX = 1, meaning odd.
Note: DIV BX places the quotient in AX and the remainder in DX for this 16-bit division.
