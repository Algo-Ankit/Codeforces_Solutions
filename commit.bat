@echo off
set /p msg=📦 Enter commit message:
for /f %%i in ('powershell -Command "Get-Date -Format yyyy-MM-dd"') do set date=%%i
git add .
git commit -m "📅 %date%: %msg%"
git push origin main

// commit.bat to automate git commit with a message and date