# Git Cheatsheet
The following table lists the various `git commands` associated with working with a git repository, making modifications, and pushing changes to GitHub. 

_This is not an extensive list and only contains the basic commands needed to set up a minimum workflow_

|Action|Description|Command Format|Example|Notes|
|:---:|:---|:---:|:---:|:---:|
|git init|Initialize a git repository in the specified directory on your local machine|`git init <directory>`|git init .|Defaults to current working directory|
|git clone|clone the repository to your local machine|`git clone <ssh/https-link-to-repo>`|git clone https://github.com/Gily-H/cisc3142_assignments_F2022.git||
|git add|Stage changes for the next commit|`git add <directory>`|git add .|You can add individual files by specifying the filenames|
|git status|Shows you which files are in the staging area, and which files are currently unstaged or untracked|`git status`|git status||
|git commit|Commit the staged changes to the next snapshot|`git commit -m "<message>"`|Not including the `-m` flag and a message will prompt the default text editor to open so that you can enter a message|
|git log|Shows the commit history of your repository|`git log`|git log|There are several [flag options](https://git-scm.com/docs/git-log) that you can add to format the history display|
|git pull|Fetch and merge the changes from the remote repository|`git pull <remote>`|git pull origin|This will update your local copy of the repo with any changes that were added to the remote repo|
|git push|Push your local branch/commits up to the remote repo|`git push <remote> <branch>`|git push origin main|This will update the remote repo with to include your commit changes|