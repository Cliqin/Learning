package com.chinahitech.shop.controller;

import com.chinahitech.shop.bean.Brand;
import com.chinahitech.shop.bean.Category;
import com.chinahitech.shop.service.CategoryService;
import com.chinahitech.shop.utils.Result;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@CrossOrigin
@RequestMapping("/category")
public class CategoryController {

    @Autowired
    private CategoryService categoryService;

    @RequestMapping("/all")
    public Result getAll(){
//      查询所有顶级分类
        List<Category> categories = categoryService.findAll();
        return Result.ok().data("items",categories);
    }

    @RequestMapping("/get")
    public Result getByParentId(Long parentId){
//      根据父ID查询子分类
        List<Category> categories = categoryService.getByParentId(parentId);
        return Result.ok().data("items",categories);
    }

}
