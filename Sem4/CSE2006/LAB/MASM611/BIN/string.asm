DATA SEGMENT
    STRING DB 'This is a sample string', '$'
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA

    START:
        MOV AX,DATA
        MOV DS,AX

; load address of the string
        LEA DX,STRING

;output the string
;loaded in dx
        MOV AH,09H
        INT 21H

;interrupt to exit
        MOV AH,4CH
        INT 21H
    HLT
    CODE ENDS
END START