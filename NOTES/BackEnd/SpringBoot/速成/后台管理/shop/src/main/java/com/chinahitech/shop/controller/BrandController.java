package com.chinahitech.shop.controller;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.chinahitech.shop.bean.Brand;
import com.chinahitech.shop.service.BrandService;
import com.chinahitech.shop.utils.Result;
import org.springframework.beans.MutablePropertyValues;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.autoconfigure.amqp.RabbitAutoConfiguration;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import java.io.Console;
import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.UUID;

@RestController
@RequestMapping("/brand")
@CrossOrigin
public class BrandController {

    @Autowired
    private BrandService brandService;

    @RequestMapping("/all")
    public Result getAll(@RequestParam(defaultValue = "1") int pageNum){

//      分页对象，传入当前页码及每页的数量
        Page<Brand> page = new Page(pageNum,10);

        Page<Brand> brands = brandService.findAll(page);
        System.out.println(brands);
        return Result.ok().data("items",brands);
    }

    @RequestMapping("/get")
    public Result getById(Long id){
        Brand brand = brandService.findById(id);
        return Result.ok().data("brand",brand);
    }

    @RequestMapping("/add")
    public Result add(Brand brand,Long categoryId){
        int r = brandService.add(brand,categoryId);
        return Result.ok();
    }

    @RequestMapping("/edit")
    public Result edit(Brand brand){
        int r = brandService.edit(brand);
        return Result.ok();
    }

//  接收上传的品牌图片
    @RequestMapping("upload")
    public String upload(MultipartFile img){
//      1. 取出文件原始名称
        String originalFilename = img.getOriginalFilename();
//      2. 为了防止文件名称重复导致覆盖，给每个文件定义一个唯一的名称
        String newFileName = UUID.randomUUID().toString().replace("-","") + originalFilename;
//      3. 获取程序运行目录
        String dirPath = System.getProperty("user.dir");
//      4. 拼接文件存储路径，最终存储到项目的upload目录下
        String path = "/" + "upload" + "/"+ newFileName;
        File destFile = new File(dirPath + path);
//      5. 如果upload目录不存在则创建
        if (!destFile.getParentFile().exists()) {
            destFile.getParentFile().mkdirs();
        }
        try {
//          6. 将前端传来的文件存储到目标路径
            img.transferTo(destFile);
            // 将相对路径返回给前端，用于显示图片
//          /upload/xxxxxxx.jpg
            return path;
        } catch (IOException e) {
            return null;
        }
    }

}
