# 服务器Python环境安装总结



------------------

- ## 安装python3.10.10

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
      #先删掉自带的python软连接
      rm -f python3
      rm -f pip3
      
      ln -sf /usr/local/bin/python3.10 /usr/bin/python3
      ln -sf /usr/local/bin/pip3.10  /usr/bin/pip3
      ```

      

  ----------

- ## 自动生成requirement.txt

  ```shell
  pip freeze > requirements.txt
  ```

- ## 安装宝塔面板

  - Centos安装脚本

    - yum install

      ```shell
      yum install -y wget && wget -O install.sh http://download.bt.cn/install/install_6.0.sh && sh install.sh ed8484bec
      ```

  - Ubuntu/Deepin安装脚本

    - ```shell
      wget -O install.sh http://download.bt.cn/install/install-ubuntu_6.0.sh && sudo bash install.sh ed8484bec
      ```

  

- ## 安装谷歌浏览器

  - ```shell
    # 搞清楚linux是32bit or 64bit
    echo "You are using $(getconf LONG_BIT) bit Linux distro."
    
    # download
    wget https://dl.google.com/linux/direct/google-chrome-stable_current_x86_64.rpm
    
    # install
    sudo yum install ./google-chrome-stable_current_*.rpm
    google-chrome --version
    
    # 2. 上传chromedriver 安装chromedriver
    sudo yum install unzip
    sudo unzip chromedriver_linux64.zip
    sudo cp chromedriver /usr/bin
    sudo chmod +x chromedriver
    sudo chromedriver --version
    ```

  - [ChromeDriver Mirror](https://link.zhihu.com/?target=http%3A//npm.taobao.org/mirrors/chromedriver/)





