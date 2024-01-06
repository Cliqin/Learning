import os
print(os.sys.path)
import dd
##from aa.bb.cc import dd


os.sys.path.append(r"C:\Users\ZMZ\Desktop\win_from_import_err") # 这里的路径改成你的路径
print('==========================')
print(os.sys.path)
from aa.bb.cc import dd


print("hello...")
print(type(os))
import aa
print(type(aa))
print(type(dd))
