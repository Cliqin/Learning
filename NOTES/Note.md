# Note

哈哈哈嘿嘿嘿![img](../PhotoBed_Typora/Note.assets/qqpyimg1680334539.gif)







## WebDriverWait

- 

  ```python
  # WebDriverWait(driver,timeout,poll_frequency=0.5,ignored_exceptions=None)
  # driver：浏览器驱动
  # timeout：最长超时时间，默认以秒为单位
  # poll_frequency：检测的间隔步长，默认为0.5s
  # ignored_exceptions：超时后的抛出的异常信息，默认抛出NoSuchElementExeception异常。
  ```

- WebDriverWait与expected_conditions结合使用

  - 

  ```
  from selenium.webdriver.support import expected_conditions as EC
  from selenium.webdriver.common.by import By
  
  wait = WebDriverWait(driver,10,0.5)
  element =wait.until(EC.presence_of_element_located((By.ID,"kw")),message="")
  ```

  

## Logger

- 

  ```py
  from loguru import logger
  #
  logger.info(f"第{retries+1}次运行")
  ```

## Document

- document.getElementById()可以取到页面上一个有id的元素

- 当一个元素有value属性的时候，其value才会有值

- 如果一个元素没有value值，那么使用document.getElementById().value时是取不到

- 输入value

- ```py
  for script in [
          f"document.getElementById('un').value='{self.xuhao}'",
          f"document.getElementById('pd').value='{self.mima}'",
          "document.getElementById('index_login_btn').click()"
  ]:
      self.driver.execute_script(script)
      
  ```

## Located_with

- #### above(),below(),等等函数是使用空间位置来定位所需的元素,很神奇

- ```py
  button = self.driver.find_elements(locate_with(By.XPATH,"//input[@type='radio']").below(formErrorContent))[0]
  ```

### expected_conditions使用方法

- ​	

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

  
