# Django后端

------

## 部署

1. 上传总Django文件

2. 在宝塔面板->网站->Python项目->添加Django项目

3. 添加所需要的数据库

4. 安装module

   1. ```shell
      #一下安装sudo和非sudo都安装一遍,防止发生错误
      #先安装依赖包
      sudo apt-get install default-libmysqlclient-dev build-essential
      
      #安装3.2版本的django,为了能匹配mysql的版本
      #
      sudo pip install django==3.2
      pip install django==3.2
      sudo pip install mysqlclient
      pip install mysqlclient
      ```

5. 如没出现问题,则开始改一些配置

   1. ```py
      #把开发者模式关掉
      DEBUG = False
      #运行所有hosts
      ALLOWED_HOSTS = ['*']
      #注释掉csrf,防止发送请求失败
      MIDDLEWARE = [
          #'django.middleware.csrf.CsrfViewMiddleware',
      ]
      #配置好你的数据库登陆信息
      DATABASES = {
          'default': {
              'ENGINE': 'django.db.backends.mysql',
              'NAME': 'server',
              'USER': 'server',
              'PASSWORD': '123456',
              'HOST': '127.0.0.1',
              'POST': 3306,
          }
      }
      #改语言和时间
      LANGUAGE_CODE = 'zh-hans'
      TIME_ZONE = 'Asia/Shanghai'
      ```

      

   

## 跨域问题

- 参考[文章](https://blog.csdn.net/weixin_67531112/article/details/127734848?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522169556999816800222851876%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=169556999816800222851876&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-127734848-null-null.142^v94^insert_down1&utm_term=django%E8%B7%A8%E5%9F%9F&spm=1018.2226.3001.4187)

- 解决跨域问题的方法

> 前端： 通过代理解决
>
> nginx代理
>
> cors解决跨域：django-cors-headers

### 后端解决

- **后端**安装跨域模块

```shell
pip install django-cors-headers
```

- 到setting.py中注册

```py
INSTALLED_APPS = (
    ...
    'corsheaders'
)
```

- 到setting.py中添加中间件


```py
MIDDLEWARE = [
    ...
    'corsheaders.middleware.CorsMiddleware',
    'django.middleware.common.CommonMiddleware',    # 这个是原本就存在的
    ...
]
```

- 到setting.py中添加如下代码


```py
CORS_ALLOW_CREDENTIALS = True
CORS_ORIGIN_ALLOW_ALL = True
# CORS_ORIGIN_WHITELIST = (
#     'http://127.0.0.1:8080',
# )
CORS_ALLOWED_ORIGINS_REGEXES=[
    r'^http://.*?$',
]
# CORS_ORIGIN_REGEXES_WHITELIST = (
#         r'^http://.*?$',
# )
CORS_ALLOW_METHODS = (
    'DELETE',
    'GET',
    'OPTIONS',
    'PATCH',
    'POST',
    'PUT',
    'VIEW',
)
 
CORS_ALLOW_HEADERS = (
    'XMLHttpRequest',
    'X_FILENAME',
    'accept-encoding',
    'authorization',
    'content-type',
    'dnt',
    'origin',
    'user-agent',
    'x-csrftoken',
    'x-requested-with',
    'Pragma',
)
```

-  设置setting.py的ALLOWED_HOSTS


```py
ALLOWED_HOSTS = ['*']
```

--------

