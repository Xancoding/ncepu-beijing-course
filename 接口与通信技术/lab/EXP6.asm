
DATAS	SEGMENT		;���ݶ�		
        
       PORTA EQU 0F0H 
       PORTB EQU 0F2H
       PORTC EQU 0F4H
       CTRL EQU  0F6H  
       
        TABLE	  DB    40H,79H,24H,30H,19H,12H,02H,78H	
		          DB    00H,18H,08H,03H,46H,21H,06H,0EH

       
       ICW1 EQU 0E0H
       ICW2 EQU 0E2H
       ICW3 EQU 0E2H
       ICW4 EQU 0E2H
       
       OCW1 EQU 0E2H
       OCW2 EQU 0E0H
       OCW3 EQU 0E0H
       
       CNT DB 00H
       
       COUNT0 EQU 0E8H
       COUNT1 EQU 0EAH
       COUNT2 EQU 0ECH
       CTRL_8253 EQU 0EEH
      
 
DATAS	ENDS


EXTRA	SEGMENT	;	;���Ӷ�
 
 
 
EXTRA	ENDS



STACK	SEGMENT  PARA  STACK  ��STACK��   ;��ջ��
STAPN	DB     100 DUP (00H)	;����100�ֽڿռ�
TOP	EQU  LENGTH  STAPN
STACK	ENDS
           
 
           
CODE	SEGMENT			
MAIN	PROC   FAR			;���̶������
				;˵��4���μĴ����ֱ�����Щ���й�
		ASSUME  CS:CODE, DS:DATAS,ES:EXTRA,SS:STACK
 
START: 
        MOV AX,DATAS
        MOV DS,AX    
        
        MOV AX, EXTRA
        MOV ES,AX
        
        MOV AX,STACK
        MOV SS,AX
      
        ; 8255 ��ʼ��
        MOV DX,CTRL
        MOV AL,90H
        OUT DX,AL    
        
        ; ����ʾһ��0
         MOV AL, CNT
         MOV BX,OFFSET TABLE
         XLAT
            
            
         MOV DX,PORTB
         OUT DX,AL 
        
        
        
        
        
        
        ; 8259 ��ʼ��
        CLI
          
        ; icw1      ��Ե
        MOV AL, 00010011B
        MOV DX,ICW1
        OUT DX,AL
        
        ; ICW2  �жϺ�
        MOV AL, 50H
        MOV DX,ICW2
        OUT DX,AL 
        
        ; ICW4
        MOV AL, 00000001B
        MOV DX,ICW4
        OUT DX,AL
        
        ; OCW1
        MOV AL,11111000B 
        MOV DX,OCW1
        OUT DX,AL
        
        ; �����ж�������
        MOV AX,0000H
        MOV ES,AX
        
        MOV BX,51H*4
        MOV AX,OFFSET MY_COUNT 
        MOV ES:[BX],AX
        
        MOV AX,CS
        MOV ES:[BX+2],AX 
        
       
        ; ��ʼ��8253
        MOV DX,CTRL_8253
        MOV AL,00010001B
        OUT DX,AL
        
        MOV DX,COUNT0
        MOV AL,05H
        OUT DX,AL 
        
        
        MOV DX,CTRL_8253
        MOV AL, 01110111B
        OUT DX,AL
        
        MOV DX,COUNT1
        MOV AL, 00H
        OUT DX,AL
        
        MOV AL,20H
        OUT DX,AL
        
        
        MOV DX,CTRL_8253
        MOV AL, 10110111B
        OUT DX,AL
        
        MOV DX,COUNT2
        MOV AL, 00H
        OUT DX,AL
        
        MOV AL,10H
        OUT DX,AL
        
        
        
        
        
        
        
        
       
       
        STI
        
        L1:
            JMP L1
        
        
        
        
        
        
        
        
 ; KEY_TEST: MOV DX,PORTA
;            IN AL,DX 
;            
;            AND AL,0FH
;            MOV BX,OFFSET TABLE
;            XLAT
;            
;            
;            MOV DX,PORTB
;            OUT DX,AL 
;            
;            MOV CX,40H
;            CALL DELAY
;            
;            JMP KEY_TEST   
        
    
            
        RET
MAIN	ENDP		;MAIN���̽��� 

DELAY PROC
    
    PUSH CX
    
    LOOP $
    
    POP CX
    
    RET
    ENDP



MY_COUNT  PROC
    
    CLI
    
    ;MOV AL, CNT
;    
;       CMP AL, 09H
;       JE  SET0
;       INC AL
;       JMP DIS_LED
; SET0:  MOV AL,00H 
        
       MOV AL,CNT
       INC AL
       AND AL, 0FH
        
        
 
   
 DIS_LED: MOV CNT,AL
          
        MOV BX,OFFSET TABLE
        XLAT
          
        MOV DX,PORTB
        OUT DX,AL
        
       
        ; ��д������
        
        MOV DX,CTRL_8253
        MOV AL,00010001B
        OUT DX,AL
        
        MOV DX,COUNT0
        MOV AL,05H
        OUT DX,AL
        
        
        
        
        
        
        
        
        ; дOCW2 �����ж�
         MOV DX,OCW2
         MOV AL, 00100000B
         OUT DX,AL
    
    
    STI
    

    
    IRET
    ENDP



CODE 	ENDS	          	;����ν���
    END   MAIN	;����Դ�������
          