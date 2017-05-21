cd %~dp0%

copy ..\build-coderudite_ronin-Desktop_Qt_5_8_0_MinGW_32bit\xbin\*.exe ..\dist_win32\bin\ /Y
copy ..\build-coderudite_ronin-Desktop_Qt_5_8_0_MinGW_32bit\xbin\*.dll ..\dist_win32\bin\ /Y
del ..\dist_win32\bin\tst_*  /F /Q

call G:\devel_tools\Qt\Qt5.8.0\5.8\mingw53_32\bin\qtenv2.bat
cd %~dp0%

windeployqt ..\dist_win32\bin

