# FastAPI后端

-------------

## 部署

1. 上传总fastapi文件

2. 在宝塔面板->网站->Python项目->添加python项目->选择gunicorn运行方式

3. 添加所需要的数据库

   1.  ![image-20231005010839766](https://oss.hejianhui.online/image-20231005010839766.png)

4. 安装module(tortoise版本要合适才行,之后再补充)

   1.  ![image-20231005012529223](https://oss.hejianhui.online/image-20231005012529223.png)

5. ### 调整配置

   1. 在列表中找到刚才建的FastAPI项目
   2. 在这一行状态列中点击"运行中"将服务关闭
   3. 点击配置
   4. 默认为`worker_class = 'geventwebsocket.gunicorn.workers.GeventWebSocketWorker'`
   5. 修改为`worker_class = 'uvicorn.workers.UvicornWorker'`
   6. 重新启动项目

6. 如顺利,继续配置代码

   1. ```py
      # 数据库绑定
      register_tortoise(
          app=app,
          db_url='mysql://fastapi:123456@localhost:3306/fastapi',
          modules={'models': ['dao.models']},
          add_exception_handlers=True,
          generate_schemas=True
      )
      #添加中间件
      app.add_middleware(
          #CORSMiddleware,
          allow_origins=["*"],
          allow_credentials=True,
          allow_methods=["*"],
          allow_headers=["*"],
      )
      ```

## 跨域问题

### 后端解决

- 到main.py中添加中间件

```py
#引入中间件
from fastapi.middleware.cors import CORSMiddleware

#添加CORS中间件
app.add_middleware(
    ...
    CORSMiddleware,
	...
)
```

