rem cl /I.\src\ /nologo /FC /Z7 /Ot .\src\idiff\main.c
gcc -I./src/ ./src/idiff/main.c -O3 -fopenmp -o gain.exe

rem cl.exe /I.\src\ /Zi /Od /EHsc /c .\src\idiff\main.c
rem link.exe /DEBUG /OUT:main.exe main.obj



rem gcc -I./src/ ./src/idiff/main.c -s -fno-asynchronous-unwind-tables -fno-ident -ffunction-sections -fdata-sections -Wl,--gc-sections


rem zig cc -I./src/ ./src/idiff/main.c -O3 -ffinite-loops
rem zig cc -I./src/ ./src/idiff/main.c -O3 -ffat-lto-objects -ffast-math
