## git 使用笔记
- 安装 sudo apt-get install git
#### 设置
- git config --global user.name "monkeybear"
- git config --global user.email "clydebear@163.com"
#### 基本命令
- git init
- git add readme.txt
- git commit -m "wrote a readme file"
- git status
- git diff readme.txt
- git log
- git log --pretty=oneline
- git reset --hard HEAD^
-  git reset --hard 3628164
- git reflog
- git diff HEAD -- readme.txt
- 撤销修改git checkout -- readme.txt
- 删除rm test.txt
- git rm test.txt
#### 远程仓库
- ssh-keygen -t rsa -C "clydebear@163.com"
- 将id_rsa.oub的内容放到gihub中
- git remote add origin git@github.com:clydebear/远程仓库名.git
- 第一次push:::git push -u origin master
- 之后的push::git push origin master
- 克隆到本地 git clone git@github.com:cldyebear/远程仓库名.git
-  git clone https://github.com/cldyebear/远程仓库名.git
#### 分支
- 创建分区并跳到分区git checkout -b dev = git branch dev  + git checkout dev
- 查看当前分支：git branch
- 切换分支：git checkout master
- 分支合并到master :   git merge dev
- 删除分支：git branch -D dev
- 查看：git log --graph --pretty=oneline --abbrev-commit
- merge后创建新的::   masterit merge --no-ff -m "merge with no-ff" dev
- 保存当前工作场景：git stash
- 查看保存的场景：git stash list
- 恢复场景：git stash apply恢复，但是恢复后，stash内容并不删除，你需要用git stash drop来删除
另一种方式是用git stash pop，恢复的同时把stash内容也删了：
- 你可以多次stash，恢复的时候，先用git stash list查看，然后恢复指定的stash，用命令：git stash apply stash@{0}
- 删除没有merge的分支：git checkout -b feature-vulcan --> git branch -D feature-vulcan强行删除
- 推送分支:git push origin master                              git push origin dev
- 抓取分支git clone git@github.com:clydebear/c_learning.git
- 创建远程的分支到本地： git checkout -b dev origin/dev
- 命令行创建远程分支：git push origin 分支名
- 命令行删除远程分支：git branch -r -d origin/branch-name  
     git push origin :branch-name  
- 命令行创建远程：git remote add origin ssh:////(本地主机名)@172.16.0.30/~/monkeybear/.git
- 抓取远程 ：git pull
- 在抓取之前要先将本地的分支与远程的分支关联：git branch --set-upstream dev origin/dev
- 多人协作的工作模式通常是这样：
首先，可以试图用git push origin branch-name推送自己的修改；
如果推送失败，则因为远程分支比你的本地更新，需要先用git pull试图合并；
如果合并有冲突，则解决冲突，并在本地提交；
没有冲突或者解决掉冲突后，再用git push origin branch-name推送就能成功！
如果git pull提示“no tracking information”，则说明本地分支和远程分支的链接关系没有创建，用命令git branch --set-upstream branch-name origin/branch-name。
- 查看远程库信息，使用git remote -v
#### 标签
- 创建标签：git tag v1.0
- git tag v0.9 历史的ID
- git show v0.9查看标签版本信息
- 给标签说名信息 git tag -a v0.1 -m "version 0.1 released" 3628164
- 可以通过-s用私钥签名一个标签：git tag -s v0.2 -m "signed version 0.2 released" fec145a
- 推送某个标签到远程，使用命令git push origin <tagname>
- 一次性推送全部尚未推送到远程的本地标签：git push origin --tags
- 如果标签已经推送到远程，要删除远程标签就麻烦一点，先从本地删除：git tag -d v0.9
- 从远程删除。删除命令也是push，但是格式如下：git push origin :refs/tags/v0.9
