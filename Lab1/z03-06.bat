@echo off
echo ��ப� ��ࠬ��஢: %1  %2
echo �����: %1
echo ��� 䠩��: %2

if "%1"=="" (goto case1) else (goto case2)
if "%2"=="" (
    echo �� ������ ��� 䠩��
    goto exit
) else if "%1" neq "ᮧ����" or if "%1" neq "㤠����" (
    echo ०�� ����� �����४⭮
    goto exit
)
 

:case1
    echo ०�� = {ᮧ����,㤠����}
    echo 䠩� = ��� 䠩��
    goto exit

:case2
    if "%2"=="" (goto case3) else (goto case4)

:case3
    echo �� ������ ��� 䠩��
    goto exit

:case4
if "%1" == "ᮧ����" (goto create)
if "%1" == "㤠����" (goto delete) else (goto operation)
:operation
    echo ०�� ����� �����४⭮
    goto exit

:create
if exist %2 (goto found)
copy NUL %2
echo 䠩� %2 ᮧ���
goto exit

:delete
if not exist %2 (goto notfound)
del %2
echo 䠩� %2 㤠��
goto exit

:found
echo 䠩� %2 㦥 ����
goto exit

:notfound
echo 䠩� %2 �� ������
goto exit

:exit
@pause