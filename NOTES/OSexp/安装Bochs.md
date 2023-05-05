# 安装Bochs

- [修改对应Ubuntu的apt源，避免安装版本不匹配的工具](#修改apt源)

- 安装必要的GCC

```shell
sudo apt-get update
sudo apt-get install gcc
sudo apt-get install build-essential
sudo apt-get install g++
sudo apt-get install libgtk2.0-dev
```

- [下载链接](http://sourceforge.net/projects/bochs/files/bochs/)	

​		下载2.6.2版本bochs-2.6.2.tar.gz

- 安装bochs

  1. 下载的压缩包`bochs-2.6.2.tar.gz`上传到虚拟机上（可以通过拖拽文件)

  2. 执行`tar zxvf bochs-2.6.2.tar.gz`解压压缩包

  3. 此时我们创建一个文件，名为bochs

  4. 进入刚刚解压的文件夹`cd bochs-2.6.2/`

  5. 记住bochs文件夹的位置,这里为`/usr/local/bochs`

  6. 执行一下代码

     ```shell
     ./configure \
     --prefix=/usr/local/bochs \
     --enable-debugger \
     --enable-disasm \
     --enable-iodebug \
     --enable-x86-debugger \
     --with-x \
     --with-x11 \
     LDFLAGS='-pthread' \
     LIBS='-lX11'
     ```

  7. 执行

     ```sh
     make 
     sudo make install
     ```

  8. 进入到bochs文件夹,运行`bin/bximage -hd -mode="flat" -size=60 -q hd60M.img`,生成hd60M.img文件

  9. 配置文件

     1. 在当前目录下,执行 `vim bochsrc.disk`

        ```d
        #Bochs运行中使用的内存，设置为32M
        megs: 32
        
        #设置真实机器的BIOS和VGA BIOS
        #修改成你们对应的地址
        romimage: file=bochs的地址/share/bochs/BIOS-bochs-latest
        vgaromimage: file=bochs的地址/share/bochs/VGABIOS-lgpl-latest
        
        #设置Bochs所使用的磁盘#设置启动盘符
        boot: disk
        
        #设置日志文件的输出
        log: bochs.out
        
        #开启或关闭某些功能，修改成你们对应的地址
        mouse: enabled=0
        keyboard_mapping: enabled=1, map=bochs的地址/share/bochs/keymaps/x11-pc-us.map
        
        #硬盘设置
        ata0: enabled=1, ioaddr1=0x1f0, ioaddr2=0x3f0, irq=14
        ata0-master: type=disk, path="hd60M.img", mode=flat, cylinders=121, heads=16, spt=63
        
        ```

        :wq 保存退出

        

     2. 运行 `bin/bochs -f bochsrc.disk`

     3. 按6,然后再按c,有反应就是成功

  10. 最后安装`nasm`汇编器

      1. 执行 `sudo apt-get install nasm`
      2. 验证一下是否成功 `nasm -version`
      3. 

  

​		





















































