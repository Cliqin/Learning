# Note



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

