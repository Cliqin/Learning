package com.chinahitech.shop.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.chinahitech.shop.bean.Brand;
import com.chinahitech.shop.bean.Category;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

@Repository
public interface BrandMapper extends BaseMapper<Brand> {

    @Insert("insert into category_brand values (#{categoryId},#{brandId})")
    public int insertBrandAndCategory(@Param("categoryId") Long categoryId,@Param("brandId") Long brandId);

}
