@echo off
cmake -S . -B ./build -G "Visual Studio 16 2019" -A "x64"
echo(
echo Open ./build/Crystal.sln...