#!/bin/bash
git add -A

# this reads all the command line arguments and 
# merges them into one string
cmt_msg="$*"

# if the length of the commit message is 0 then we 
# have to request a commit message from the user
if [ ${#cmt_msg} = 0 ]
then
    echo Enter commit message:
    read cmt_msg
fi

git commit -m "$cmt_msg"

# ask the user if they want to push the commit
echo Do you want to push this commit? [y / n]
read push_wish
echo $push_wish
# only push if answer is y all other inputs are considered as n
if [ $push_wish = "y" ]
then
    branch=$(git rev-parse --abbrev-ref HEAD)
    echo pushing to $branch...
    git push --set-upstream origin $branch
else
    echo not pushing to github
fi
