

# Python基础复习总结



用input()函数

```python
password = input("请输入密码:")
print('您刚刚输入的密码是:%s' % password)
```

注意: 

- input()的小括号中放入的是提示信息，用来在获取数据之前给用户的一个简单提示 
- input()在从键盘获取了数据以后，会存放到等号右边的变量中 
- input()会把用户输入的任何值都作为字符串来对待

## elif(else if)功能

```python
score = 77
if score>=90:
	print('本次考试，等级为A')
elif score>=80:
	print('本次考试，等级为B')
elif score>=70:
	print('本次考试，等级为C')
elif score>=60:
	print('本次考试，等级为D')
elif score<60:
	print('本次考试，等级为E')
```

-----

## for循环

```python
for 临时变量 in 列表或者字符串等可迭代对象:
	循环满足条件时执行的代码
```

- range()表示范围

-------

## 字符串高级(str)

```python
# - 获取长度:len                   len函数可以获取字符串的长度。
# - 查找内容:find                  查找指定内容在字符串中是否存在，如果存在就返回该内容在字符串中第一次出现的开始位置索引值，如果不存在，则返回-1.
# - 判断:startswith,endswith      判断字符串是不是以谁谁谁开头/结尾
# - 计算出现次数:count              返回 str在start和end之间 在 mystr里面出现的次数
# - 替换内容:replace               替换字符串中指定的内容，如果指定次数count，则替换不会超过count次。
# - 切割字符串:split               通过参数的内容切割字符串
# - 修改大小写:upper,lower         将字符串中的大小写互换
# - 空格处理:strip                去空格
# - 字符串拼接:join                 字符串拼接
# - 字符串与二进制的转化:encode,decode	encode转为二进制,decode转为字符串
```

```python
s = 'china'
print(len(s))   #5

s1 = 'china'
print(s1.find('a'))  #4

s2 = 'china'
print(s2.startswith('h'))  #False
print(s2.endswith('n'))   #False

s3 = 'aaabb'
print(s3.count('b'))     #2

s4 = 'cccdd' 
print(s4.replace('c','d'))    #ddddd

s5 = '1#2#3#4'
print(s5.split('#'))    #['1', '2', '3', '4']

s6 = 'china'
print(s6.upper())     #CHINA

s7 = 'CHINA'
print(s7.lower())      #china

s8 = '   a   '
print(len(s8))       #7

print(len(s8.strip()))   #1

s9 = 'a'
print(s9.join('hello'))   #haealalao
```

-------

## 列表高级(list)

- #### 索引为**负数**形式


```python
windows[-1]#windows = [1,2,3,4,5] 他选择的是最后一个 这样就不需要用len来选择了 太聪明了挖槽
```

- #### 形式:方括号[]


```python
food_list = ['铁锅炖大鹅','酸菜五花肉']
print(food_list)      ['铁锅炖大鹅', '酸菜五花肉']
```

- #### 添加

  - append
  - insert
  - extend

```python
# append  追加   在列表的最后来添加一个对象/数据
food_list.append('小鸡炖蘑菇')
print(food_list)       #['铁锅炖大鹅', '酸菜五花肉', '小鸡炖蘑菇']

# insert  插入
char_list = ['a','c','d']    #['a', 'c', 'd']
print(char_list)
# index的值就是你想插入数据的那个下标
char_list.insert(1,'b')
print(char_list)      #['a', 'b', 'c', 'd']

# extend 继承
num_list = [1,2,3]
num1_list = [4,5,6]

num_list.extend(num1_list)
print(num_list)        #[1, 2, 3, 4, 5, 6]
```



- #### 修改

  - ##### 直接赋值

```py
city_list = ['北京','上海','深圳','武汉','西安']

print(city_list)

# 将列表中的元素的值修改
# 可以通过下标来修改，注意列表中的下标是从0开始的
city_list[4] = '大连'
print(city_list)
```



- #### 查询

```py
ball_list = ['篮球','台球']

# 在控制台上输入你喜欢的球类 然后判断是否不在这个列表中
ball = input('请输入您喜欢的球类')

if ball not in ball_list:
    print('不在')
else:
    print('在')
```

- #### 删除

```py
#del根据下标直接删除
a_list = [1,2,3,4,5]
del a_list[2]
print(a_list)

#pop是删除列表中的最后一个元素
b_list = [1,2,3,4,5]
print(b_list)
b_list.pop()
print(b_list)

#remove根据元素来删除列表
c_list = [1,2,3,4,5]
print(c_list)
c_list.remove(3)
print(c_list)
```

------

## 元组高级(tuple)

- #### 形式:小括号()

- #### 不同:不能修改里面的内容

- #### 相同:访问元素的方式与列表相同

```py
a_tuple = (1,2,3,4)

print(a_tuple[0])
print(a_tuple[1])
```

- #### 注意:

  - #### 定义只有一个元素的元组，需要在唯一的元素后写一个逗号

```py
# 当元组中只要一个元素的时候  那么他是整型数据
# 定义只有一个元素的元组，需要在唯一的元素后写一个逗号
a_tuple = (5)
print(type(a_tuple))

b_tuple = (5,)
print(type(b_tuple))
```

------

## 切片

- #### 字符串、列表、元组都支持切片操作

- #### 字符串

```py
s ='hello world'

# 在切片中直接写一个下标
print(s[0])      #h

#####!左闭右开区间!###   包含坐标的数据 不包含右边的数据
print(s[0:4])      #hell

# 是从起始的值开始  一直到末尾
print(s[1:])       #ello world

# 是下标为0的索引的元素开始 一直到第二参数为止   遵循左闭右开区间
print(s[:4])        #hell

# hello  world
# 从下标为0的位置开始 到下标为6的位置结束  每次增长2个长度 遵循左闭右开区间
print(s[0:6:2])      #hlo
```

------

## 字典高级(dic)

- #### 形式:{}

```py
person = {'name':'吴签','age':28}
```



- #### 访问方式

```py
# 访问person的name
print(person['name'])
print(person['age'])

# 使用[]的方式，获取字典中不存在的key的时候  会发生异常   keyerror
print(person['sex'])

# 不能使用.的方式来访问字典的数据
print(person.name)

print(person.get('name'))
print(person.get('age'))

# 使用.的方式，获取字典中不存在的key的时候  会返回None值
print(person.get('sex'))
```



- #### 修改

  - 直接赋值

  
  ```py
  # 修改name的值为法外狂徒
  person['name'] = '法外狂徒'
  ```



- #### 添加

  - 直接赋值

  
  ```py
  # 如果使用变量名字['键'] = 数据时  这个键如果在字典中不存在  那么就会变成新增元素
  person['age'] = 18
  ```



- #### 删除

  - #### del方式

    - ##### 删除指定元素

    - ##### 删除整个字典

  - #### clear方式

    - ##### 清空字典

  - #### pop方式

    - ##### pop('key')删除指定键名的项

    - ##### popitem()

```py
person = {'name':'老马','age':18}
#删除字典中指定的某一个元素
del person['age']
#删除整个字典
del person
#清空字典 但是保留字典对象
person.clear()
#删除之pop方式
person.pop('name')
person.popitem()
```



- #### 遍历

```py
# (1) 遍历字典的key
# 字典.keys() 方法 获取的字典中所有的key值  key是一个变量的名字 我们可以随便起
for key in person.keys():
    print(key)

# (2) 遍历字典的value
#字典.values()方法  获取字典中所有的value值   value也是一个变量 我们可以随便命名
for value in person.values():
    print(value)

# (3) 遍历字典的key和value
for key,value in person.items():
	print(key,value)


# (4) 遍历字典的项/元素
for item in person.items():
    print(item)
```



- #### 复制字典


使用 `copy()` 方法来复制字典

```py
thisdict =	{
  "brand": "Porsche",
  "model": "911",
  "year": 1963
}
mydict = thisdict.copy()
print(mydict)
```

使用 `dict()` `方法创建字典的副本`

```py
thisdict =	{
  "brand": "Porsche",
  "model": "911",
  "year": 1963
}
mydict = dict(thisdict)
print(mydict)
```

---------

## 文件

- #### 使用open函数，可以打开一个已经存在的文件，或者创建一个新文件,需要自己关闭文件

*默认情况下使用gdk的编码,要想汉字或中文,要指定编码格式为encoding = 'utf-8'*

```py
f = open('test.txt', 'w') #默认情况下使用gdk的编码,要想汉字或中文,要指定编码格式为encoding = utf-8
```


- #### 使用with open函数,会自动关闭文件

```py
def down_load(page,content):
# with open（文件的名字，模式，编码）as fp:
# fp.write(内容)
	with open('douban_'+str(page)+'.json','w',encoding='utf‐8')as fp:
		fp.write(content)
```



- #### 文件路径

  绝对路径：指的是绝对位置，完整地描述了目标的所在地，所有目录层级关系是一目了然的

  - 例如： `D:\python`，从电脑的盘符开始，表示的就是一个绝对路径。 

  

  相对路径：是从当前文件所在的文件夹开始的路径。

  -  `test.txt` ，是在当前文件夹查找 `test.txt `文件 
  - `./test.txt`，也是在当前文件夹里查找 `test.txt` 文件， 
  - `./` 表示的是当前文件夹。
  - `../test.txt` ，从当前文件夹的上一级文件夹里查找 `test.txt` 文件。 
  - `../` 表示的是上一级文件夹
  - `demo/test.tx` ，在当前文件夹里查找 `demo` 这个文件夹，并在这个文件夹里查找 `test.txt` 文件。

- #### 访问模式

  | 访问模式 | 说明                                                         |
  | :------: | :----------------------------------------------------------- |
  |    r     | 以只读方式打开文件。文件的指针将会放在文件的开头。如果文件不存在，则报错。这是==默认模式==。 |
  |    w     | 打开一个文件只用于写入。如果该文件已存在则将其==覆盖==。如果该文件不存在，**==创建新文件==**。 |
  |    a     | 打开一个文件用于追加。如果该文件已存在，文件指针将会放在文件的结尾。也就是说，新的内容将会被写入到已有内容之后。如果该文件不存在，创建新文件进行写入。 |
  |    r+    | 打开一个文件用于读写。文件指针将会放在文件的开头。           |
  |    w+    | 打开一个文件用于读写。如果该文件已存在则将其覆盖。如果该文件不存在，创建新文件。 |
  |    a     | 打开一个文件用于读写。如果该文件已存在，文件指针将会放在文件的结尾。文件打开时会是追加模式。如果该文件不存在，创建新文件用于读写。 |
  |    rb    | 以二进制格式打开一个文件用于只读。文件指针将会放在文件的开头。 |
  |    wb    | 以二进制格式打开一个文件只用于写入。如果该文件已存在则将其覆盖。如果该文件不存在，创建新文件。 |
  |    ab    | 以二进制格式打开一个文件用于追加。如果该文件已存在，文件指针将会放在文件的结尾。也就是说，新的内容将会被写入到已有内容之后。如果该文件不存在，创建新文件进行写入。 |
  |   rb+    | 以二进制格式打开一个文件用于读写。文件指针将会放在文件的开头。 |
  |   wb+    | 以二进制格式打开一个文件用于读写。如果该文件已存在则将其覆盖。如果该文件不存在，创建新文件。 |
  |   ab+    | 以二进制格式打开一个文件用于读写。如果该文件已存在，文件指针将会放在文件的结尾。如果该文件不存在，创建新文件用于读写。 |

- #### 读与写

  - 写数据(write)


```py
f = open('test.txt', 'w') 
f.write('hello world, i am here!\n' * 5) 
f.close()
```

- 读数据(read),(readline),(readlines)

```py
f = open('test.txt', 'r')
content = f.read(5) # 最多读取5个数据
print(content)
print("‐"*30) # 分割线，用来测试

content = f.read() # 从上次读取的位置继续读取剩下的所有的数据
print(content)

```

- 读数据(readline)

```py
f = open('test.txt', 'r')

content = f.readline()
print("1:%s" % content)

content = f.readline()
print("2:%s" % content)

f.close()
```

- 读数据(readlines)

`readlines`可以按照行的方式把整个文件中的内容进行**一次性读取**，并且返回的是一个列表，其中每一行为列表的 一个元素。

```py
f = open('test.txt', 'r')

content = f.readlines()
print(type(content))

for temp in content:
print(temp)

f.close()
```

---------


## 序列化与反序列化

通过文件操作，我们可以将字符串写入到一个本地文件。但是，如果是一个**对象(例如列表、字典、元组等)，就无法直接写入到一个文件**里，需要对这个对象进行序列化，然后才能写入到文件里。

利用json模块来实现序列化与反序列化

- ### 序列化


```py
import json
file = open('names.txt', 'w')
names = ['zhangsan', 'lisi', 'wangwu', 'jerry', 'henry', 'merry', 'chris']
# file.write(names) 出错，不能直接将列表写入到文件里
# 可以调用 json的dumps方法，传入一个对象参数
result = json.dumps(names)
# dumps 方法得到的结果是一个字符串
print(type(result)) # <class 'str'>
# 可以将字符串写入到文件里
file.write(result)
file.close()
```

#### 注意:

`dumps()`方法的作用是把**对象转换成为字符串**，它本身不具备将数据写入到文件的功能。

`dump()`方法可以在将对象转换成为字符串的同时，指定一个文件对象，把转换后的**字符串写入到这个文件**里。

```py
import json

# dump方法可以接收一个文件参数，在将对象转换成为字符串的同时写入到文件里
json.dump(names, file)
file.close()
```



- ### 反序列化

  - #### 使用loads或load方法


  ```py
  import json
  
  # 调用loads方法，传入一个字符串，可以将这个字符串加载成为Python的对象
  result = json.loads('["zhangsan", "lisi", "wangwu", "jerry", "henry", "merry", "chris"]')
  
  print(type(result)) # <class 'list'>
  ```

  ```py
  import json
  
  # 以可读方式打开一个文件
  file = open('names.txt', 'r')
  
  # 调用load方法，将文件里的内容加载成为一个Python对象
  result = json.load(file)
  
  print(result)
  file.close()
  ```

  区别:

  #### loads传入的是**字符串** , load传入的是**文件**



## 异常

- #### try...except语句

```py
#try:
	#可能会出现异常的代码块
#except 异常的类型:
	#出现异常以后的处理语句

try:
	f = open('test.txt', 'r')
	print(f.read())
except FileNotFoundError:
	print('文件没有找到,请检查文件名称是否正确')
```

-----

## Logger

可以输出日志

```py
from loguru import logger
#
logger.info(f"第{retries+1}次运行")
```



------

