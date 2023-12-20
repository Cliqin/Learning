# 安装

在Ubuntu上，你可以使用以下命令来移除 Docker 相关的软件包：

```sh
sudo apt-get purge docker-ce docker-ce-cli containerd.io
```

请注意，这个命令会移除 Docker CE、其命令行工具和 containerd.io 软件包。如果你有其他相关的软件包，你可能需要将它们一并添加到命令中。

在Ubuntu上，你可以使用以下命令来安装 Docker CE：

```shell
codesudo apt-get update
sudo apt-get install -y docker-ce docker-ce-cli containerd.io
```

这将更新软件包列表并安装 Docker CE、其命令行工具以及 containerd.io 软件包。


在Ubuntu上，你可以使用以下命令来添加Docker CE的仓库、修改仓库地址并更新缓存：

```shell
# 添加Docker CE仓库
sudo add-apt-repository "deb [arch=amd64] https://mirrors.aliyun.com/docker-ce/linux/ubuntu $(lsb_release -cs) stable"

# 修改仓库地址
sudo sed -i 's/download.docker.com/mirrors.aliyun.com\/docker-ce/g' /etc/apt/sources.list.d/docker-ce.list

# 更新缓存
sudo apt-get update
```

这些命令执行的操作与之前的CentOS上的命令类似，但有一些不同之处，因为Ubuntu使用不同的包管理系统（APT）。

Docker使用中会涉及到各种端口，为了方便使用最好关闭防火墙

~~~shell
# 关闭
systemctl stop firewalld
# 禁止开机启动防火墙
systemctl disable firewalld
~~~

查看docker版本

~~~
docker -v
~~~

配置Docker国内镜像加速（可选），https://cr.console.aliyun.com/cn-hangzhou/instances/mirrors?accounttraceid=92fb8c360fab4609bf7caac2380dc136fnjo

启动Docker

~~~shell
systemctl start docker  # 启动docker服务

systemctl stop docker  # 停止docker服务

systemctl restart docker  # 重启docker服务
~~~

# 创建镜像

## 一、镜像操作指令

| FROM       | 指定基础镜像                                 | FROM centos:6               |
| ---------- | -------------------------------------------- | --------------------------- |
| ENV        | 设置环境变量，可在后面指令使用               | ENV key value               |
| COPY       | 拷贝本地文件到镜像的指定目录                 | COPY ./mysql-5.7.rpm /tmp   |
| RUN        | 执行Linux的shell命令，一般是安装过程的命令   | RUN yum install gcc         |
| EXPOSE     | 指定容器运行时监听的端口，是给镜像使用者看的 | EXPOSE 8080                 |
| ENTRYPOINT | 镜像中应用的启动命令，容器运行时调用         | ENTRYPOINT java -jar xx.jar |

## 二. 基于CentOS基础镜像构建Java应用镜像

#### 1. 上传JDK

创建文件夹，将jdk安装包上传到该目录下

~~~shell
mkdir -p /root/dockerfile/java
~~~

#### 2. 编写dockerfile

在/root/dockerfile/java目录下创建文件dockerfile_java,内容如下：

~~~dockerfile
FROM centos:7
# 配置环境变量，JDK的安装目录
ENV JAVA_DIR=/usr/local

# 拷贝jdk和java项目的包
COPY ./jdk-8u131-linux-x64.tar.gz $JAVA_DIR/
COPY ./docker-demo.jar /tmp/app.jar

# 安装JDK
RUN cd $JAVA_DIR \
 && tar -xf ./jdk-8u131-linux-x64.tar.gz \
 && mv ./jdk1.8.0_131 ./java8

# 配置环境变量
ENV JAVA_HOME=$JAVA_DIR/java8
ENV PATH=$PATH:$JAVA_HOME/bin

# 暴露端口
EXPOSE 8080
# 入口，java项目的启动命令
ENTRYPOINT java -jar /tmp/app.jar
~~~

#### 3. 生成镜像

~~~shell
#docker build -f 文件名 -t 镜像名 .代表从当前目录
docker build -f dockerfile_java -t myjava:1.0 .
~~~

#### 4. 验证镜像是否生成成功

~~~shell
docker images
~~~

#### 5. 启动容器

~~~shell
docker run --name myjava -d -p 8080:8080 myjava:1.0
~~~

## 二. 通过java镜像构建应用镜像

#### 1. 编写dockerfile

~~~dockerfile
FROM java:8-alpine
COPY ./docker-demo.jar /tmp/app.jar
# 暴露端口
EXPOSE 8080
# 入口，java项目的启动命令
ENTRYPOINT java -jar /tmp/app.jar
~~~

#### 3. 生成镜像

~~~shell
#docker build -f 文件名 -t 镜像名 .代表从当前目录
docker build -f dockerfile_java2 -t myjava:2.0 .
~~~

#### 4. 验证镜像是否生成成功

~~~shell
docker images
~~~

#### 5. 启动容器

~~~shell
docker run --name myjava2 -d -p 8081:8080 myjava:2.0
~~~

