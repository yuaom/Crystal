@echo off

REM ############################################################################
SET WDK=%ProgramFiles(x86)%\Windows Kits\10\Include\10.0.18362.0
REM ############################################################################

del .\build\CMakeCache.txt
cmake -S . -B ./build -G "Visual Studio 16 2019" -A "x64" -DWDK="%WDK%"
echo(
echo Open ./build/Crystal.sln...