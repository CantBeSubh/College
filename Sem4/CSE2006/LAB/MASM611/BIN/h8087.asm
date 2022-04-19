data segment 
radius dd 3.0
height dd 4.0
d dd 0.33
area dd ?
data ends
 
code segment 
assume cs:code,ds:data
.8087
start:
	mov ax,data
	mov ds,ax
	finit
	fld height
	fld radius 
	fmul radius
	fmul 	
	fldpi 
	fmul
	fld d
	fmul
	fst area
hlt 
code ends
end start