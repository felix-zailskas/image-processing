#!/bin/bash
git add -A
cmt_msg="$*"
git commit -m "$cmt_msg"
branch=$(git rev-parse --abbrev-ref HEAD)
git push --set-upstream origin $branch