# readRAWfile

###### 先做voxelizer ######

### 實作概念
先把raw、inf檔讀進來(0為空氣)
再找出接觸空氣的所有面，並定義好它的VAO、VBO，一次畫出來
**注意:千萬不要把每個面定義一個正方形的VAO、VBO然後再while迴圈裡依序跑每個面，這樣跑迴圈會很慢**

![](./image/code0.png)
![](./image/code1.png)

光照是用phing shading及blinn-phong phading，可按B鍵切換
*參考LearnOpenGL*

![](./image/code2.png)

### 執行畫面
- resolution為21*21*21的球體

![](./image/ball21.png)
- resolution為67*67*67的球體

![](./image/ball67.png)

- resolution為257*257*257的球體

![](./image/ball257.png)

- resolution為476*301*238的茶壺

![](./image/tea.png)


###### 跟之前的程式比把一些畫圖的東西都定義header和cpp ######