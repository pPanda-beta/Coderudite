cd %~dp0%

xcopy predefined_data ..\dist_win32\data /s /y

rd ..\dist_win32\data\webroot /Q

mklink /J ..\dist_win32\data\webroot  ..\client_side\public_html
