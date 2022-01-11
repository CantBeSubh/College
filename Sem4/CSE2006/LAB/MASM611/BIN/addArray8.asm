DATA SEGMENT
    ARRAY DB 05H, 61H, 0FH, 10H, 23H ;use source index
DATA ENDS
CODE SEGMENT
          ASSUME CS:CODE,DS:DATA
    START:
          MOV    AX,DATA ;mandatory (used as a catalyst for moving ds data)
          MOV    DS,AX ;mandatory (access ds memory)
          MOV    CL,05H ;count is stored here cant use loop if used in any other register than CL
          MOV    AL,00H
    RPT:                            ;label thing to indicate the start of the loop
          ADD    AL,ARRAY[SI]
          INC    SI
          LOOP   RPT                ;if not, use DEC and then use JUMP ON NO 0 (JNZ)
          ;if loop is not used, repeat the following until done.
          ;ADD AL, ARRAY[SI]
          ;INC SI
          ;ADD AL, ARRAY[SI]
          HLT
CODE ENDS
END START