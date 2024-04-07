@echo off

::set the path where your web server's root is (iProgramInCpp's is at C:\gtcache -- don't ask why)
set WEBSRVROOT=C:\gtcache

::set the emscripten root to your emscripten installation (iProgramInCpp's is at C:\emsdk)
echo * Calling emsdk_env.bat.
set EMSCRIPTEN_ROOT=C:\emsdk
set OLDCD=%cd%
cd /d %EMSCRIPTEN_ROOT%
call emsdk_env.bat
cd %OLDCD%

::working directory
echo * Creating wasm working directory.
md wasm
cd wasm

::create output directory
echo * Creating output directory.
del /s /q dist
md dist

::note: Why the hell do I need to pop it into a separate window? When I don't, the batch
::file just stops...

::configure build
echo * Configuring build.
start emcmake cmake -S.. -Bbuild -GNinja "$@"
echo * PRESS ANY KEY when emcmake is done.
pause > nul

::build
echo * Starting build.
cmake --build build
:: echo * PRESS ANY KEY when CMake is done. --- Seems like we don't need that for cmake itself.
:: pause > nul

::for me only
echo * Copying to your webserver.
xcopy /E /Y dist\ %WEBSRVROOT%\dist\
move %WEBSRVROOT%\dist\wasm_shell.html %WEBSRVROOT%\dist\reminecraftpe.html

::cd back
echo * And we are done!!
cd %OLDCD%
