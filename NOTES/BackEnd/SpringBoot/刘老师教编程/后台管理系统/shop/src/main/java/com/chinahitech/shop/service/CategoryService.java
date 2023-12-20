package com.chinahitech.shop.service;

import com.chinahitech.shop.bean.Category;
import com.chinahitech.shop.mapper.CategoryMapper;
import jdk.nashorn.internal.ir.ReturnNode;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CategoryService {
    @Autowired
    private CategoryMapper categoryMapper;
    public List<Category> findAll() {
        return categoryMapper.findSAll();
    }
    public List<Category> getByParentId(Long parentId) {
        return categoryMapper.getByParentId(parentId);
    }
}
