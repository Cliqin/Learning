# Alembic的使用

Alembic 是一款轻量型的数据库迁移工具，它与SQLAlchemy一起共同为 Python 提供数据库管理与迁移支持。

## Alembic 的应用

Alembic 使用 SQLAlchemy 作为数据库引擎，为关系型数据提供创建、管理、更改和调用的管理脚本，协助开发和运维人员在系统上线后对数据库进行在线管理。

同任何 Python 扩展库一样，我们可以通过 pip 来快速的安装最新的稳定版 Alembic 扩展库 `pip install alembic`。

## 安装

```sh
pip install alembic
```

## 创建 Alembic 迁移环境

```sh
alembic init alembic
```

生成的迁移脚本目录如下：

```text
├── alembic
│   ├── README
│   ├── env.py
│   ├── script.py.mako
│   └── versions
```

- **alembic** 目录：迁移脚本的根目录，放置在应用程序的根目录下，可以设置为任意名称。在多数据库应用程序可以为每个数据库单独设置一个 Alembic 脚本目录。
- **README**文件：说明文件，初始化完成时没有什么意义。
- **env.py**文件：一个 python 文件，在调用 Alembic 命令时该脚本文件运行。
- **script.py.mako** 文件：是一个 mako 模板文件，用于生成新的迁移脚本文件。
- **versions** 目录：用于存放各个版本的迁移脚本。初始情况下为空目录，通过 `revision` 命令可以生成新的迁移脚本。

## 配置环境

在alembic.ini中

```ini
sqlalchemy.url = driver://user:pass@localhost/dbname
#替换成
sqlalchemy.url = mysql://root:123456@localhost:3306/volunteer
```

在env.py中

```py
# from myapp import mymodel
# target_metadata = mymodel.Base.metadata
# target_metadata = None
# 替换成
from Volunteer import models
target_metadata = models.Base.metadata
```



## 生成迁移脚本

当 Alembic 配置环境创建完成后，可以通过 Alembic 的子命令 revision 来生成新的迁移脚本。

```sh
alembic revision -m "first create script"
```

初始的迁移脚本中并没有实际有效的内容，相当于一个空白的模板文件「增加了版本信息」。如果对整改工程的数据表进行修改后，再次运行 revision 子命令可以看到新生成的脚本文件中的内容增加了我们对数据表的改变内容。

## 自动生成迁移脚本

```sh
alembic revision --autogenerate

#更新
alembic upgrade head
```

















