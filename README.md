# probation-repo
1) make a new dir.
mkdir intership
pwd
2) Clone a remote repo 
git clone https://github.com/AnnaSagina/probation-repo.git
git clone https://AnnaSagina@bitbucket.org/AnnaSagina/probation-repo.git

check that a remote repo has been addded:
$ cd probation-repo/
$ git remote
origin <- cloned repo

3) now create your branch:
git branch <branchName>

change your branch from master to the new one:
git checkout <branchName>

4) Create a new directory for your projects &add a README file with description:
mkdir <dirName>
cd <dirName>
touch README
echo "That's <your name>'s repo with her code" > README
*you may use vi or any other editor to fill the README file.

5) Add your file to git.
$ git status
On branch ANNA
Untracked files:
  (use "git add <file>..." to include in what will be committed)

        ./

git add .  
git commit -m "My first commit"

6) Add your changes to master branch (create a pull request)
git push <remote_server> <branch>
git push origin ANNA
enter your credentials when prompted.

....
* to download latest changes:
	git checkout master
	git pull upstream master
	git checkout <branchName>
	git merge master
