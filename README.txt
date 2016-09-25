The project exhibits all the requirements for "File Catalogue".
The run.bat file is been given the input as
TestPath /s /d /f"syracuse"

TestPath - is the test path created for testing.
/s - it shows the recursive directory search
/d - it shows the duplicate files
/f - it shows the string search i.e. the files which contains the search text.
Please note that, there is no space between /f and the string to be searched.

Also, path has to be given as the first input. Rest of the inputs could be given in
any order.


After the first run, the user is asked for any more texts to be search. The user
could also give 'e' as an input to exit the program.
If the user gives the text, the file pattern in which to search for the text is been asked.
E.g - if you give "testing" *.*, it will show all the files which has "testing" word in it.
"testing" *.rtf will show only rtf files which have "testing" word in it.


This continues unless the user enter 'e' - to exit the program.


