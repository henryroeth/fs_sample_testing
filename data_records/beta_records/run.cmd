@ECHO OFF

REM Set working directory
pushd %~dp0

REM Delete existing combined file


setlocal ENABLEDELAYEDEXPANSION
set total=0
set count=0

REM Set total
for %%i in (*.csv) DO set /a total+=1

for %%i in (*.csv) DO (
cls
echo:Combining CSV files [!count!/%total%]
if !count!==0 (
for /f "delims=" %%j in ('type "%%i"') do echo %%j >> combined.csv
) else if %%i NEQ combined.csv (
for /f "skip=1 delims=" %%j in ('type "%%i"') do echo %%j >> combined.csv
)
set /a count+=1
)

ECHO Finished
PAUSE >NUL