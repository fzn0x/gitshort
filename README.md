![GitShort](./GITSHORT.png)

GitShort helps you to use git more quickly, just plug it in PATH of environment variables of your WINDOWS Operation System.

Available Commands:
- gitset (init, git branch -M, add origin)
- gitcm (init / add, commit, push)

GitSet Usage :
GitSet will automically init project folder if there is no **.git** folder. Warn you if no arguments needed.

if you get "failed to push some refs" error on git push, you can set the default branch in the last argument of gitset command. the default is `master`.
```bash
gitset <origin-url> <branch-name (optional, default: master)>
```

GitCm Usage :
GitCm will automically init project folder if there is no **.git** folder and warn you to init and set the origin first before push. 

gitcm will add all the new files and changed files by default.
```bash
gitcm <commit message> <the last argument is the branch name>
```

Download the executable files here : [GitShort Github](https://github.com/fauzan121002/gitshort/releases/tag/1.0.0)