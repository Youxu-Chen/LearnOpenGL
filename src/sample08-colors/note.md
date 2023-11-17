# Notes
- 物体的颜色是由光源的颜色与自身颜色两者所影响，我们眼睛能看到的颜色其实是物体吸收了光源的部分颜色，同时反色了其他颜色。反射的颜色就是我们看到的颜色。
```c
glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
glm::vec3 toyColor(1.0f, 0.5f, 0.31f);
glm::vec3 result = lightColor * toyColor; // = (1.0f, 0.5f, 0.31f); 每个分量相乘
```