#                                         JS逆向

## 安装第三方库

- 安装执行js文件的execjs	`pip install pyexecjs2`

  - 使用方法

  ```py
  res = execjs.compile(open('filename','r',encoding='utf-8').read()).call('fname',param)
  ```

  

- 安装加密算法库	`npm install crypto-js`



 



## MD5加密算法







请求数据:dic

dic转为str

str转为json str



json str压缩(进制流压缩)会变成一个数组

压缩的数据转为密文数(进制流压缩)



密文解压为数组 	

数组解压为jsonstr





base64用来做编码处理 `base64.b64encode()`

zlib是用来压缩包 `zlib.compress()`	`zlib.decompress()`

