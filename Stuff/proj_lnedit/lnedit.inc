      include \masm32\include\windows.inc
      include \masm32\include\masm32.inc
      include \masm32\include\gdi32.inc
      include \masm32\include\user32.inc
      include \masm32\include\kernel32.inc
      include \masm32\include\Comctl32.inc
      include \masm32\include\comdlg32.inc
      include \masm32\include\shell32.inc
      include \masm32\include\oleaut32.inc
      include \masm32\include\msvcrt.inc
      include \masm32\macros\macros.asm

      includelib \masm32\lib\masm32.lib
      includelib \masm32\lib\gdi32.lib
      includelib \masm32\lib\user32.lib
      includelib \masm32\lib\kernel32.lib
      includelib \masm32\lib\Comctl32.lib
      includelib \masm32\lib\comdlg32.lib
      includelib \masm32\lib\shell32.lib
      includelib \masm32\lib\oleaut32.lib
      includelib \masm32\lib\msvcrt.lib

	include rsrc.inc

_DlgMainProc proto :dword,:dword,:dword,:dword
_NewListProc proto :dword,:dword,:dword,:dword
_NewEditProc proto :dword,:dword,:dword,:dword
_AddToList proto :dword
_SaveOrNot proto
_StringBrief proto :dword
_StringBack proto :dword
_SetText proto :dword
_ModifyOriText proto :dword,:dword
_memcpy proto
_UpdateWindow proto :dword
_GotoDlgProc proto :dword,:dword,:dword,:dword
_OptionDlgProc proto :dword,:dword,:dword,:dword
_DisplayMsg proto :dword
_ReplaceText proto 
_ReplaceDlgProc proto :dword,:dword,:dword,:dword
_RpcText proto :dword,:dword,:dword,:dword,:dword
_IsFormatted proto :dword
_StringToUnicode proto
_FindText proto :dword

_AddHandler proto :dword,:dword,:dword,:dword
_ProcHandler proto :dword,:dword,:dword,:dword

_ExportTxt proto :dword,:dword
_ImportTxt proto :dword
_slstrlen proto

ID_TIMER equ 1

.data?
	hInstance dd ?
	hIcon dd ?
	hWinMain dd ?
	
	hListO dd ?
	hListN dd ?
	hEditO dd ?
	hEditN dd ?
	hStatusLine dd ?
	hBtnModify dd ?
	hBtnSave dd ?
	hBtnGoto dd ?
	hBtnFind dd ?
	hBtnImp dd ?
	hBtnExp dd ?
;	hStatusByteO dd ?
;	hStatusByteN dd ?
	hBackBmp dd ?
	
	hBrushTr dd ?
	
	hFile dd ?
	hFile2 dd ?
	
	lpOldListProc dd ?
	lpOldEditProc dd ?
	
	lpFileBuff dd ?
	lpFileBuff2 dd ?
	
	lpscOri dd ?
	lpscNew dd ?
	
	lpTemp dd ?
	lpLineRecords dd ?
	lpBackBmp dd ?
	
	szFileName db 512 dup(?)
	szStringO db 512 dup (?)
	szStringN db 512 dup (?)
	szTemp db 512 dup (?)
	szToFind db 64 dup (?)
	szToReplace db 64 dup (?)
	szReplaced db 32 dup (?)
	
	dwTemp dd ?
	
	nTotalLine dd ?
	nRealLine dd ?
	nFileSizeNew dd ?
	
	bIsModified dd ?
	bScrolling dd ?
	bIsOpened dd ?
	
	
.data
	ddTable\ ;00
			dd 0bh,11h,5,5,0,6,0,1,0ffh,0,1,0,0,0,0,0
			dd 5,5,0,0,0,0,1,5,0,0,0,0,0,0bh,0,0
			dd 0ch,15 dup (0)
			dd 0,0,0,5,5,0,1,0bh,8 dup (0)
			;01
			dd 0feh,0ff01h,5,0fffefeh,0ff01h,0ah,0ah,0ah,23h,01fefefeh,0ah,0fe0ah,6,0fefe05h,15h,5
			dd 10h,5,23h,19h,5,0ff01h,0,0ffffh,0feh,0,2,6,0bh,0bh,0ffffh,0
			dd 16 dup (0)
			dd 16 dup (0)
			;02
			dd 0ff05h,0fh,6,19h,0ah,0fh,0ah,0ah,14h,1eh,0fh,14h,15h,0ah,0ah,0ah
			dd 0fh,0fh,0fe19h,0ah,10ff05h,14h,14ff05h,6,8 dup (0)
			dd 16 dup (0)
			dd 16 dup (0)
			;03
			dd 06ff05h,0bh,5,01ffh,12 dup (0)
			dd 16 dup (0)
			dd 16 dup (0)
			dd 16 dup (0)
			;04
			dd 0bh,6,6,0ah,0ah,11 dup (0)
			dd 16 dup (0)
			dd 16 dup (0)
			dd 16 dup (0)
			;05
			dd 0fe05h,28h,23h,0ah,0ah,1,0,2,8 dup (0)
			dd 16 dup (0)
			dd 16 dup (0)
			dd 16 dup (0)
			;06
			dd 06ffh,5,0ffh,0,0ff05h,6,5,0,5,5,0ffh,0bh,14h,0,0,0
			dd 16 dup (0)
			dd 16 dup (0)
			dd 16 dup (0)
	
	szDisplayName db 'Mutiline Editor v1.6',0
	szError db '����',0
	szCaptionFind db '�滻�ַ���',0
	szNewSc db 'NewSc\',0
	szTxt1 db 'txt',0
	szSaveOrNot db '�ļ����޸ģ��Ƿ񱣴棿',0
	szFailOpen db '�޷����ļ���',0
	szFormat2 db '�ű��ļ�(*.msc)',0,'*.msc',0,'�����ļ�',0,'*.*',0,0
	szFormat3 db '�ı��ļ�(*.txt)',0,'*.txt',0,0
	szCountingLines db '���ڼ���������...',0
	szAddingString db '���ڻ�ȡ�ı�...',0
	szConvertingString db '����ת���ı�...',0
	szSaveTxtSuccess db '����TXT�ɹ���',0
	szSaveTxtFail db '����TXTʧ�ܣ�',0
	szImpTxtSuccess db '����TXT�ɹ���',0
	szImpTxtFail db '����TXTʧ�ܣ���������������',0
	szLineOver db '�������������',0
	szSaveSuccess db '�����ļ��ɹ���',0
	szTextNotFound db '�ַ���δ�ҵ���',0
	szRpcFormat db '�������%d���滻',0
	szNotTxt db '�ű���ʽ����ȷ����������',0
	szInstruction db '�س�',09h,09h,'���汾���޸�',0dh,0ah,
				'PageDown',09h,'��һ��(������)',0dh,0ah,
				'PageUp',09h,09h,'��һ��(������)',0dh,0ah,
				'Ctrl+S',09h,09h,'���������޸ĵ��ļ�',0dh,0ah,
				'Ctrl+G',09h,09h,'��ת��ĳ��',0dh,0ah,
				'Ctrl+F',09h,09h,'�滻�ı�',0dh,0ah,0