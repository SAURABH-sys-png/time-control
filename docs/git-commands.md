so the very first command we have is 


git init 

-> creates a new subdirectory names .git it contains oall the fiels related to the repo and the version tree or repositry skeleton 


git clone 
-> clones the existing repository 

qs -> 
is it mandatory to have the github or git cli link for it ?


git add .
git commit -m "test"


////

-> .gitignore 
-> # ignres , *.cpp, *.smthing skips

git diff -> give you the changes all of them after the git add .  which is staging of the files 

git diff // the core difference between git diff and git diff --cached
now if i just want to modify the files which are only non staged but diferent from the main working directory then 


git rm --cached <filename>

git log 
git log -p -2 -> p is the patched ie changes in the each commit and 2 is limit to how many commit to be shown 

git log --stat



git reset HEAD <filename>


git checkout -- <filename>


