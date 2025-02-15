# Python爬虫复习总结

## 模块下载(pip下载)

找到解释器(interpreter)位置:

- 我的位置![image-20220705150957392](https://oss.hejianhui.online/image-20220705150957392.png)
- 安装在D盘的python当中的Scripts文件夹里![image-20220705151852157](https://oss.hejianhui.online/image-20220705151852157.png)

如图![image-20220705152509639](https://oss.hejianhui.online/image-20220705152509639.png)

第三方库

- [Python 第三方库、模块安装和卸载方法以及国内镜像-逍遥峡谷 (icoa.cn)](https://www.icoa.cn/a/886.html)

- ```py
  pip install python-docx -i https://pypi.douban.com/simple
  ```

  


----------------------------------------------

## Urllib

### 导包

- 正常导包

```py
import urllib.request
import urllib.parse
```

- 相对路径导包

```py
import sys
# 去上一路径
sys.path.append("..")
from Public import *
```



----------------------------------------------

### Urllib库使用

```py
urllib.request.urlopen() #模拟浏览器向服务器发送请求

#response 服务器返回的数据
	#response的数据类型是HttpResponse
	#字节‐‐>字符串
		解码decode
	#字符串‐‐>字节
		编码encode
	read()       #字节形式读取二进制 扩展：rede(5)返回前几个字节
	readline()   #读取一行
	readlines()  #一行一行读取 直至结束
	getcode()    #获取状态码
	geturl()     #获取url
	getheaders() #获取headers
	
urllib.request.urlretrieve()
	#请求网页
	#请求图片
	#请求视频

```

----------------------------------------------

### 请求

```py
import urllib.request

url = 'http://www.baidu.com'

#response的数据类型是HttpResponse
response = urllib.request.urlopen(url)

# （3）获取响应中的页面的源码  content 内容的意思
# read方法  返回的是字节形式的二进制数据
# 我们要将二进制的数据转换为字符串

# 二进制--》字符串  解码  decode('编码的格式')
content = response.read().decode('utf-8')

# （4）打印数据
print(content)
```

----------------------------------------------

### 响应所用的六个方法

| 类型                  | models.Response                 |
| :-------------------- | :------------------------------ |
| response.read()       | 字节形式读取二进制              |
| response.read(5)      | 字节形式读取二进制              |
| response.readline()   | 字节形式读取二进制              |
| response.readlines()  | 字节形式读取二进制              |
|                       |                                 |
| response.geturl()     | 获取请求的url                   |
| response.getcode()    | 响应的状态码                    |
| response.getheaders() | 响应的头信息,获取是一个状态信息 |

```py
import urllib.request

url = 'http://www.baidu.com'

# 模拟浏览器向服务器发送请求
response = urllib.request.urlopen(url)

# 一个类型和六个方法
response是HTTPResponse的类型
print(type(response))

# 按照一个字节一个字节的去读
content = response.read()  #字节形式读取二进制
print(content)

# 返回多少个字节
content = response.read(5)  #字节形式读取二进制
print(content)

# 读取一行
content = response.readline()  #字节形式读取二进制
print(content)

#一行一行读,直到读完
content = response.readlines()  #字节形式读取二进制
print(content)

# 返回状态码  如果是200了 那么就证明我们的逻辑没有错
print(response.getcode())

# 返回的是url地址
print(response.geturl())

# 获取是一个状态信息
print(response.getheaders())

# 一个类型 HTTPResponse
# 六个方法 read  readline  readlines  getcode geturl getheaders
```

------------------------------------------

### get请求

- #### urllib.parse.quote（）

  **导包**

  **将中文转换为Unicode格式**

  **urllib.request.Request来定制请求头**

```py
import urllib.request
import urllib.parse

url = 'https://www.baidu.com/s?wd='
headers = {'User‐Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, likeGecko) Chrome/74.0.3729.169 Safari/537.36'}

url = url + urllib.parse.quote('小野')
request = urllib.request.Request(url=url,headers=headers)
response = urllib.request.urlopen(request)
```

- #### urllib.parse.urlencode（）

  **导包**

  **将多个参数转换为Unicode格式**

  **urllib.request.Request来定制请求头**

```py
import urllib.request
import urllib.parse

url = 'http://www.baidu.com/s?'
data = {'name':'小刚','sex':'男',}

data = urllib.parse.urlencode(data)
url = url + data
print(url)

headers = {'User‐Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML,likeGecko) Chrome/74.0.3729.169 Safari/537.36'}

request = urllib.request.Request(url=url,headers=headers)
```

------------------------------

### post请求

- #### urllib.request.Request来定制请求头

```py
eg:百度翻译
import urllib.request
import urllib.parse

url = 'https://fanyi.baidu.com/sug'

headers = {'user‐agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, likeGecko) Chrome/74.0.3729.169 Safari/537.36'}

keyword = input('请输入您要查询的单词')

#参数是放在请求对象定制的方法中，编码之后需要调用encode方法
data = {'kw':keyword}

data = urllib.parse.urlencode(data).encode('utf‐8')
request = urllib.request.Request(url=url,headers=headers,data=data)
response = urllib.request.urlopen(request)

print(response.read().decode('utf‐8'))
```

----------------------------------------------

总结:

- ### `get请求方式的参数必须编码，参数是拼接到url后面，编码之后不需要调用encode方法` 

- ### `post请求方式的参数必须编码，参数是放在请求对象定制的方法中，编码之后需要调用encode方法`

------

### Cookie登陆

- #### 绕过登陆直接进入页面


```py
#cookie中携带着你的登陆信息   如果有登陆之后的cookie,那么我们就可以携带cookie进入到任何页面
#referer判断当前路径是不是由上一个路径进来的   一般情况下 是做图片防盗链
```

- #### 通过selenium获取cookies


```py
from selenium import webdriver

url = 'http://www.baidu.com'
driver = webdriver.Chrome()
driver.get(url)

#关键步骤
cookies = {data['name']:data['value']for data in driver.get_cookies()}
```

----

### Handler处理器(代理手段)

Handler 定制更高级的请求头（随着业务逻辑的复杂 请求对象的定制已经满足不了我们的需求（动态cookie和代理 不能使用请求对象的定制）

handler、build_opener、open

- 基本格式


```py
import urllib.request

request = urllib.request.Request(url=url,headers=headers)

handler = urllib.request.HTTPHandler() #HTTPHandle      handler
opener = urllib.request.build_opener(handler) #build_opener
response = opener.open(request) #open

print(response.read().decode('utf‐8'))

```

- 使用代理时,只需要变一个名字(ProxyHandler)

```py
eg:
import urllib.request

request = urllib.request.Request(url=url,headers=headers)

proxies = {'http':'117.141.155.244:53281'}

handler = urllib.request.ProxyHandler(proxies=proxies) #ProxyHandler
opener = urllib.request.build_opener(handler)
response = opener.open(request)

content = response.read().decode('utf‐8')
```

- 代理池

​	random模块

```py
proxies_pool = [
    {'http':'118.24.219.151:16817'},
    {'http':'118.24.219.151:16817'},
]

import random

proxies = random.choice(proxies_pool)
```

-------------------------------------------------

## 解析数据

### XPATH

- ### lxml

  安装模块(lxml)


```py
1.安装lxml库
	pip install lxml ‐i https://pypi.douban.com/simple
2.导入lxml.etree
	from lxml import etree
3.#etree.parse() #解析本地文件
	html_tree = etree.parse('XX.html')
4.#etree.HTML() #服务器响应文件
	html_tree = etree.HTML(response.read().decode('utf‐8')
4.html_tree.xpath(xpath路径)
```

- #### 开始解析

  解析规则


```py
from lxml import etree

# xpath解析
# （1）本地文件                                                etree.parse
# （2）服务器响应的数据  response.read().decode('utf-8') *****   etree.HTML()

# xpath解析本地文件
tree = etree.parse('070_尚硅谷_爬虫_解析_xpath的基本使用.html')

#tree.xpath('xpath路径')

# 查找ul下面的li
li_list = tree.xpath('//body/ul/li')

# 查找所有有id的属性的li标签
# text()获取标签中的内容
li_list = tree.xpath('//ul/li[@id]/text()')

# 找到id为l1的li标签  注意引号的问题
li_list = tree.xpath('//ul/li[@id="l1"]/text()')

# 查找到id为l1的li标签的class的属性值
li = tree.xpath('//ul/li[@id="l1"]/@class')

# 查询id中包含l的li标签
#/text()来获取值
li_list = tree.xpath('//ul/li[contains(@id,"l")]/text()')

# 查询id的值以l开头的li标签
li_list = tree.xpath('//ul/li[starts-with(@id,"c")]/text()')

#查询id为l1和class为c1的
li_list = tree.xpath('//ul/li[@id="l1" and @class="c1"]/text()')

li_list = tree.xpath('//ul/li[@id="l1"]/text() | //ul/li[@id="l2"]/text()')

# 判断列表的长度
print(li_list)
print(len(li_list))
```

---------------------------------------------------

### JSONPATH

- #### 安装模块


```py
#pip安装：
pip install jsonpath
```

- #### 使用


```py
import json
import jsonpath

obj = json.load(open('json文件', 'r', encoding='utf‐8'))
ret = jsonpath.jsonpath(obj, 'jsonpath语法')
```

![1](https://oss.hejianhui.online/1.png)

![2](https://oss.hejianhui.online/2.png)

----------------

### BEAUTIFUL SOUP

- #### 安装模块


```py
1.安装
pip install bs4
```

- #### 接收对象


```py
#2.导入
from bs4 import BeautifulSoup

#3.创建对象
#服务器响应的文件生成对象
soup = BeautifulSoup(response.read().decode(), 'lxml')

#本地文件生成对象
soup = BeautifulSoup(open('1.html'), 'lxml')

#注意：默认打开文件的编码格式gbk所以需要指定打开编码格式
```

- #### 节点定位

  比较人性化


```py
1.根据标签名查找节点
	soup.a 【注】只能找到第一个a
	soup.a.name
	soup.a.attrs
    	
2.函数

(1)#.find(返回一个对象)
	find('a')：#只找到第一个a标签
	find('a', title='名字')#标签
	find('a', class_='名字')#标签  class要改成class_
    
(2)#.find_all(返回一个列表)
	find_all('a') 查找到所有的a
	find_all(['a', 'span']) 返回所有的a和span #注意格式,要写成列表
	find_all('a', limit=2) 只找前两个a
    
(3)#.select(根据选择器得到节点对象)【推荐】(CSS语法)
	# element
		eg:p
        print(soup.select('a'))	#多个a标签
        
	# .class
		eg:.firstname
        print(soup.select('.a1'))
        
	# #id
		eg:#firstname
        print(soup.select('#l1'))
        
	# 属性选择器
		[attribute]
			eg:li = soup.select('li[class]')
		[attribute=value]
			eg:li = soup.select('li[class="hengheng1"]')
        
	# 层级选择器
    
    	#  后代选择器
		element element
			div p
        
        # 子代选择器
        # 注意：很多的计算机编程语言中 如果不加空格不会输出内容  但是在bs4中 不会报错 会显示内容
		element>element
			div>p
        
        # 找到div标签和p标签的所有的对象
		element,element
			div,p    
				eg:soup = soup.select('a,span')
```

- #### 注意


```py
# select()一般返回的是列表,记得选其中的内容才会变成标签
```



- #### 获取内容


```py
(1) #获取节点内容：适用于标签中嵌套标签的结构
	obj.string
	obj.get_text() #【推荐】
    
(2) #节点的属性
	tag.name  #获取标签名
		eg:tag = find('li')
			print(tag.name)
                      
	
    #ag.attrs将属性值作为一个字典返回
    # 格式为 {'id': 'p1', 'class': ['p1']}
                  
(3) #获取节点属性值
	obj.attrs.get('title') #【常用】
	obj.get('title')
	obj['title']
```

#### 注意:

```py
# 如果标签对象中 只有内容 那么string和get_text()都可以使用

# 如果标签对象中 除了内容还有标签 那么string就获取不到数据 而get_text()是可以获取数据
```

---------

## Selenium

### 如何安装selenium？ 

- 操作谷歌浏览器驱动下载地址 

- [驱动下载地址](http://chromedriver.storage.googleapis.com/index.html )

  - 谷歌驱动和谷歌浏览器版本之间的映射表

    - [映射表](http://blog.csdn.net/huilan_same/article/details/51896672 )

  - 查看谷歌浏览器版本 谷歌浏览器右上角‐‐>帮助‐‐>关于 

  - `pip install selenium`

-------

### 使用前提

```py
#（1）导入：
	from selenium import webdriver
#（2）创建谷歌浏览器操作对象：
	path = 谷歌浏览器驱动文件路径
	browser = webdriver.Chrome(path)
#（3）访问网址
	url = 要访问的网址
	browser.get(url)
```

------

### 元素定位

导包

```py
from selenium.webdriver.common.by import By
```

```py
#1.find_element_by_id
	eg:button = browser.find_element_by_id('su')
    
#2.find_elements_by_name
	eg:name = browser.find_element_by_name('wd')
    
#3.find_elements_by_xpath
	eg:xpath1 = browser.find_elements_by_xpath('//input[@id="su"]')
    
#4.find_elements_by_tag_name
	eg:names = browser.find_elements_by_tag_name('input')
    
#5.find_elements_by_css_selector改为browser.find_elements(by=By.CSS_SELECTOR, value='')
	eg:my_input = browser.find_elements_by_css_selector('#kw')[0]
    browser.find_elements(by=By.CSS_SELECTOR, value='.header-login-entry')[0]
    
#6.find_elements_by_link_text
	eg:browser.find_element_by_link_text("新闻")
    
#7.find_elements(locate_with())  above(),below(),等等函数是使用空间位置来定位所需的元素,很神奇
	driver.find_elements(locate_with(By.XPATH,"//input[@type='radio']").below(formErrorContent))[0]
```

----------

### 元素信息与交互

```py
#获取元素属性
	.get_attribute('class')
#获取元素文本
	.text
#获取标签名
	.tag_name

#点击:
	click()
#输入:
	send_keys()
#后退操作:
	browser.back()
#前进操作:
	browser.forword()
#模拟JS滚动:
	js='document.documentElement.scrollTop=100000'
	browser.execute_script(js) 执行js代码
#获取网页代码：
	page_source
    
#截图:
	browser.save_screenshot('baidu.png')
    
#退出：
	browser.quit()
```

--------

### Document

document.getElementById()可以取到页面上一个有id的元素

当一个元素有value属性的时候，其value才会有值

如果一个元素没有value值，那么使用document.getElementById().value时是取不到

输入value

```py
for script in [
        f"document.getElementById('un').value='{self.xuhao}'",
        f"document.getElementById('pd').value='{self.mima}'",
        "document.getElementById('index_login_btn').click()"
]:
    self.driver.execute_script(script)
    
```

-----

### WebDriverWait

```python
WebDriverWait(driver ,timeout ,poll_frequency=0.5 ,ignored_exceptions=None)
# driver：浏览器驱动
# timeout：最长超时时间，默认以秒为单位
# poll_frequency：检测的间隔步长，默认为0.5s
# ignored_exceptions：超时后的抛出的异常信息，默认抛出NoSuchElementExeception异常。
```

### expected_conditions

```python
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions


driver = webdriver.Chrome()
driver.get('https://work.weixin.qq.com/')
time.sleep(5)

locator = (By.CSS_SELECTOR, '[data-js-click-report-log="79506103,web_first_khq_click"]')
element = driver.find_element(*locator)
EC = expected_conditions                  # expected_conditions简写EC


# 对比页面标题：对比driver.title与传入值
# EC.title_is('标题内容')             # 判断：'标题内容' == driver.title
# EC.title_contains('标题内容')       # 判断：'标题内容' in driver.title

# 对比url
# EC.url_to_be('url')             # 判断：'url' == driver.current_url
# EC.url_changes('url')           # 判断：'url' != driver.current_url
# EC.url_contains('url')          # 判断：'url' in driver.current_url
# EC.url_matches('正则表达式')      # 判断：driver.current_url是否匹配正则表达式

# 对比窗口
# n = 3
# EC.number_of_windows_to_be(n)    # 判断：当前窗口数量 = n

# 对比frame
# EC.frame_to_be_available_and_switch_to_it(locator)  # 元素所在frame可切入则切入并返回True，否则返回False

# 对比弹窗
# EC.alert_is_present()   # 有弹窗则返回弹窗对象，否则返回False

# 判断元素是否出现：指元素在网页中是否存在，不关注元素状态
# EC.presence_of_element_located(locator)        # 返回元素对象
# EC.presence_of_all_elements_located(locator)   # 返回元素列表

# 判断元素状态
# EC.element_to_be_clickable(locator)    # 元素可点击则返回元素对象，否则返回False
# EC.element_to_be_clickable(element)    # 元素可点击则返回元素对象，否则返回False

# EC.element_to_be_selected(element)                          # 元素是否被选中
# EC.element_located_to_be_selected(locator)                  # 元素是否被选中
# EC.element_selection_state_to_be(element, True)             # 元素是否被选中
# EC.element_located_selection_state_to_be(locator, True)     # 元素是否被选中
# EC.staleness_of(element)                                    # 元素不存在

# 判断元素是否可见（注意传入参数）
# EC.visibility_of(element)                       # 元素可见则返回元素对象，否则返回False
# EC.visibility_of_element_located(locator)       # 元素可见则返回元素对象，否则返回False
# EC.visibility_of_all_elements_located(locator)  # 全部可见则返回元素列表，否则返回False
# EC.visibility_of_any_elements_located(locator)  # 返回可见元素列表，无则返回空列表

# EC.invisibility_of_element(element))            # 元素不可见则返回元素对象，否则返回False
# EC.invisibility_of_element_located(locator)     # 元素不可见则返回元素对象，否则返回False

# 对比元素属性值
# EC.text_to_be_present_in_element(locator, '文本内容')                  # '文本内容' in element.text
# EC.text_to_be_present_in_element_value(locator, '文本内容')            # '文本内容' in element.get_attribute("value")
# EC.text_to_be_present_in_element_attribute(locator, '属性', '属性值')   # '属性值'  in element.get_attribute("属性")
# EC.element_attribute_to_include(locator, '属性')                       # element.get_attribute("属性") is not None

# 组合判断
# li = [EC.title_is('标题内容'), EC.url_to_be('url')]   # expected_conditions列表：['EC1', 'EC2', '...']
# EC.any_of(li)                                        # 或：任意一个满足则返回True，否则返回False
# EC.all_of(li)                                        # 且：全部都满足则返回True，否则返回False
# EC.none_of(li)                                       # 非：全部都不满足则返回True，否则返回False

driver.quit()
```

-----

### 两者结合使用

```py
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By

wait = WebDriverWait(driver,10,0.5)

element =wait.until(EC.presence_of_element_located((By.ID,"kw")),message="")
```



------------------------------------------------



## Request

### 基本使用

安装

```'py
pip install requests
```

response的属性以及类型

| 类型                 |  models.Response   |
| :------------------- | :----------------: |
| response.text        |    获取网站源码    |
| response.encoding    | 访问或定制编码方式 |
| response.url         |   获取请求的url    |
| response.content     |   响应的字节类型   |
| response.status_code |    响应的状态码    |
| response.headers     |    响应的头信息    |

### Get请求

requests.get()

```py
import requests
url = 'http://www.baidu.com/s?'

headers = {
'User‐Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML,like Gecko) Chrome/65.0.3325.181 Safari/537.36'}

data = {
'wd':'北京'
}

# url  请求资源路径
# params 参数
# kwargs 字典
response =
requests.get(url,params=data,headers=headers)

#定制参数
	#参数使用params传递
	#参数无需urlencode编码
	#不需要请求对象的定制
	#请求资源路径中？可加可不加
    

```

总结

- ##### （1）参数使用params传递

- ##### （2）参数无需urlencode编码

- ##### （3）不需要请求对象的定制

- ##### （4）请求资源路径中的？可以加也可以不加

------------------------------------

### Post请求

requests.post()

```py
import requests
post_url = 'http://fanyi.baidu.com/sug'

headers={
'User‐Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36(KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36'}

data = {
'kw': 'eye'
}

# url 请求地址
# data 请求参数
# kwargs 字典

r = requests.post(url = post_url,headers=headers,data=data)

```

总结

- ##### （1）post请求 是不需要编解码

- ##### （2）post请求的参数是data

- ##### （3）不需要请求对象的定制

----

### get和post区别？

1. ### get请求的参数名字是**params** 		post请求的参数的名字是**data**

2. ### 请求资源路径后面可以不加? 

3. ### 不需要手动编解码 

4. ### 不需要做请求对象的定制

-------------------------------------------

### 代理

```py
proxy定制
在请求中设置proxies参数
参数类型是一个字典类型
eg:
import requests
url = 'http://www.baidu.com/s?'

headers = {
'user‐agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML,like Gecko) Chrome/65.0.3325.181 Safari/537.36'
}

data = {
'wd':'ip'
}

proxy = {
'http':'219.149.59.250:9797'
}
r = requests.get(url=url,params=data,headers=headers,proxies=proxy)

with open('proxy.html','w',encoding='utf‐8') as fp:
fp.write(r.text)
```

-------------------------------------------------

### Session

```py
session = requests.session()
# 验证码的url的内容
response_code = session.get(code_url)
# 注意此时要使用二进制数据  因为我们要使用的是图片的下载
content_code = response_code.content
```

--------------------------------

## Scrapy

- 



