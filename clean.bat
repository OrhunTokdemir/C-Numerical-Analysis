@echo off
echo Cleaning build files...

if exist "build" (
    rmdir /s /q build
    echo Build directory removed.
) else (
    echo No build directory found.
)

REM Remove any generated executables in root
if exist "*.exe" del *.exe

echo Clean complete!
pause
