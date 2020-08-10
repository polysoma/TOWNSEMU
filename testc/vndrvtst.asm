						ASSUME	CS:CODE

						PUBLIC	IOWriteByte
						PUBLIC	IOReadByte

CODE					SEGMENT

TOWNSIO_VNDRV_AUXCOMMAND		EQU		2F18H
TOWNS_VNDRV_AUXCOMMAND_PRINT	EQU		09H
TOWNS_VNDRV_AUXCOMMAND_DUMP		EQU		09H



VNDRV_PRINT				PROC
;	[EBP+4] Return EIP   [EBP+8] Pointer to c_str
						PUSH	EBP
						MOV		EBP,ESP
						PUSH	EAX
						PUSH	EBX

						MOV		EBX,[EBP+8]
						MOV		AL,TOWNS_VNDRV_AUXCOMMAND_PRINT
						OUT		TOWNSIO_VNDRV_AUXCOMMAND,AL

						POP		EBX
						POP		EAX
						POP		EBP
						RET
VNDRV_PRINT				ENDP



VNDRV_DUMP				PROC
;	[EBP+4] Return EIP   [EBP+8] Pointer    [EBP+0CH] Length
						PUSH	EBP
						MOV		EBP,ESP
						PUSH	EAX
						PUSH	EBX
						PUSH	ECX

						MOV		EBX,[EBP+8]
						MOV		ECX,[EBP+0CH]
						MOV		AL,TOWNS_VNDRV_AUXCOMMAND_DUMP
						OUT		TOWNSIO_VNDRV_AUXCOMMAND,AL

						POP		ECX
						POP		EBX
						POP		EAX
						POP		EBP
						RET
VNDRV_PRINT				ENDP



CODE					ENDS
						END

