set /p value=请输入commit内容:
del /s /q *.exe     rem 删除所有的exe
git add .
git commit -m "%value%"
git push origin master
pause