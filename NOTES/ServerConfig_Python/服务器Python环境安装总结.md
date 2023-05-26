# 服务器安装Python爬虫环境

------------------

## Centos Python

​	安装python3.10.10

- 因为官网源下载比较慢，所以这里备份并替换为阿里云源，这样做不是必须的，视你的情况而定。

  - ```shell
    #替换为阿里云源
    curl -o /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-7.repo
    curl -o /etc/yum.repos.d/epel.repo http://mirrors.aliyun.com/repo/epel-7.repo
    ```

- 然后安装依赖

  - ```shell
    yum -y groupinstall "Development tools"
    yum install -y ncurses-devel gdbm-devel xz-devel sqlite-devel tk-devel uuid-devel readline-devel bzip2-devel libffi-devel
    yum install -y openssl-devel openssl11 openssl11-devel
    ```

- 编译主要需要注意的问题是设置编译FLAG，以便使用最新的openssl库。

  - ```shell
    export CFLAGS=$(pkg-config --cflags openssl11)
    export LDFLAGS=$(pkg-config --libs openssl11)
    ```

- 开始安装

  - ```shell
    #解压然后进入目录
    tar xvzf Python-3.10.10.tgz
    cd Python-3.10.10
    
    # 安装
    ./configure --enable-optimizations && make altinstall
    
    # 安装完成后验证一下是否安装成功
    /usr/local/bin/python3.10 --version
    /usr/local/bin/pip3.10 --version
    ```

- 设置软链接

  - ```shell
    cd /usr/bin
    
    ll | grep python
    
    sudo rm ./python # 删除原有的软连接文件
    sudo rm ./pip
    sudo rm ./pip3
    
    sudo ln -s /usr/local/python3.10/bin/python3.10 /usr/bin/python
    sudo ln -s /usr/local/python3.10/bin/pip3.10 /usr/bin/pip
    sudo ln -s /usr/local/python3.10/bin/pip3.10 /usr/bin/pip3
    ```

  **注：这里我们不能将系统中的 python3 命令链接到 python3.10 版本（这里我已经踩坑），因为 python3.10 版本还是发型版本，并不是稳定版本，若更改后则会导致 Ubuntu 系统下的很多 python 文件无法打开（比如你的 gnome 终端）！**


----

## Ubuntu Python

​	安装python3.10.10

- 执行以下命令更新源：

  - ```shell
    sudo apt-get update
    ```


  - 执行以下命令安装 Python3 的一些依赖库：

    - ```shell
      sudo apt-get install libqgispython3.10.4
      sudo apt-get install libpython3.10-stdlib
      ```


  - 开始安装

    ```shell
    #解压然后进入目录
    tar xvJf Python-3.10.10.tar.xz
    cd Python-3.10.10
    
    # 安装
    ./configure --prefix=/usr/local/python3.10
    
    make
    sudo make install
    
    # 安装完成后验证一下是否安装成功
    /usr/local/bin/python3.10 --version
    /usr/local/bin/pip3.10 --version
    ```


  - 设置软链接

    - ```shell
      cd /usr/bin
      
      ll | grep python
      
      sudo rm ./python # 删除原有的软连接文件
      sudo rm ./pip
      sudo rm ./pip3
      
      sudo ln -s /usr/local/python3.10/bin/python3.10 /usr/bin/python
      sudo ln -s /usr/local/python3.10/bin/pip3.10 /usr/bin/pip
      sudo ln -s /usr/local/python3.10/bin/pip3.10 /usr/bin/pip3
      ```

**注：这里我们不能将系统中的 python3 命令链接到 python3.10 版本（这里我已经踩坑），因为 python3.10 版本还是发型版本，并不是稳定版本，若更改后则会导致 Ubuntu 系统下的很多 python 文件无法打开（比如你的 gnome 终端）！**


​    

----------

## 	自动生成requirement.txt

```shell
pip freeze > requirements.txt
```


---

## 安装宝塔面板

- Centos安装脚本

  - yum install

    ```shell
    yum install -y wget && wget -O install.sh http://download.bt.cn/install/install_6.0.sh && sh install.sh ed8484bec
    ```

- Ubuntu/Deepin安装脚本

  - ```shell
    wget -O install.sh http://download.bt.cn/install/install-ubuntu_6.0.sh && sudo bash install.sh ed8484bec
    ```


-----



## Centos Chrome driver

- ```shell
  # 搞清楚linux是32bit or 64bit
  echo "You are using $(getconf LONG_BIT) bit Linux distro."
  
  # download
  wget https://dl.google.com/linux/direct/google-chrome-stable_current_x86_64.rpm
  
  # install
  sudo yum install ./google-chrome-stable_current_*.rpm
  
  #查看版本
  google-chrome --version
  
  # 2. 上传chromedriver 安装chromedriver
  sudo yum install unzip
  sudo unzip chromedriver_linux64.zip
  sudo cp chromedriver /usr/bin
  sudo chmod +x chromedriver
  sudo chromedriver --version
  ```
  
- [ChromeDriver Mirror](https://link.zhihu.com/?target=http%3A//npm.taobao.org/mirrors/chromedriver/)



---

## Ubuntu Chrome driver

- ```shell
  # 搞清楚linux是32bit or 64bit
  echo "You are using $(getconf LONG_BIT) bit Linux distro."
  
  # download  或者自己导入
  wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
  
  # install
  sudo dpkg -i google-chrome-stable_current_amd64.deb
  
  #查看版本
  google-chrome --version
  
  # 2. 上传chromedriver 安装chromedriver
  sudo apt-get install unzip
  sudo unzip chromedriver_linux64.zip
  
  # 先放到share里,然后在再bin里建立软连接
  mv -f chromedriver /usr/local/share/chromedriver
  ln -s /usr/local/share/chromedriver /usr/local/bin/chromedriver
  ln -s /usr/local/share/chromedriver /usr/bin/chromedriver
  
  #修改权限
  sudo chmod +x chromedriver
  
  sudo chromedriver --version
  ```

- [ChromeDriver Mirror](https://registry.npmmirror.com/binary.html?path=chromedriver/)



----

## 安装模块

- httpx

```sh
sudopython -m pip install httpx --user
```

