// #include "framework.h"

// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

// #define STB_IMAGE_IMPLEMENTATION
// #include "std_image.h"

// #include "shader.h"

// namespace CYXDemo {
// class MyTexture : public Framework {
//     void Startup() {
//         m_shader = Shader("./shaders/sample05-transformation01.vs", "./shaders/sample05-transformation01.fs");    

//         stbi_set_flip_vertically_on_load(true);

//         // create texture object
//         // unsigned int texture;
//         glGenTextures(1, &m_texture1);
//         glBindTexture(GL_TEXTURE_2D, m_texture1);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//         // write texture data into texture object
//         int width, height, nrChannels;
//         unsigned char *data = stbi_load("./images/container.jpg", &width, &height, &nrChannels, 0);
//         if (data){
//             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//             glGenerateMipmap(GL_TEXTURE_2D);
//             stbi_image_free(data);
//         }
//         else {
//             std::cout << "Failed to load texture" << std::endl;
//             return;
//         }

//         // create texture object
//         // unsigned int texture;
//         glGenTextures(1, &m_texture2);
//         glBindTexture(GL_TEXTURE_2D, m_texture2);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//         // write texture data into texture object
//         // int width, height, nrChannels;
//         data = stbi_load("./images/awesomeface.png", &width, &height, &nrChannels, 0);
//         if (data){
//             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//             glGenerateMipmap(GL_TEXTURE_2D);
//             stbi_image_free(data);
//         }
//         else {
//             std::cout << "Failed to load texture" << std::endl;
//             return;
//         }

//         float vertices[] = {
//         //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
//             0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
//             0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
//             -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
//             -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
//         };
//         unsigned int indices[] = {  
//             0, 1, 3, // first triangle
//             1, 2, 3  // second triangle
//         };
//         unsigned int VBO, EBO;
//         glGenVertexArrays(1, &m_vao);
//         glGenBuffers(1, &VBO);
//         glGenBuffers(1, &EBO);
//         // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//         glBindVertexArray(m_vao);

//         glBindBuffer(GL_ARRAY_BUFFER, VBO);
//         glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//         glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//         glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

//         glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//         glEnableVertexAttribArray(0);
//         // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(3* sizeof(float)));
//         // glEnableVertexAttribArray(1);
//         glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));
//         glEnableVertexAttribArray(1);

//         // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//         glBindBuffer(GL_ARRAY_BUFFER, 0); 

//         m_shader.use();
//         glUniform1i(glGetUniformLocation(m_shader.ID, "texture1"), 0);
//         m_shader.setInt("texture2", 1);

//     }

//     void Render() {
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         glm::mat4 trans = glm::mat4(1.0f);
        
//         // translate first, then rotate
//         trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//         trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        
//         m_shader.use();
//         glUniform1i(glGetUniformLocation(m_shader.ID, "texture1"), 0);
//         m_shader.setInt("texture2", 1);

//         unsigned int transformLoc = glGetUniformLocation(m_shader.ID, "transform");
//         glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

//         glActiveTexture(GL_TEXTURE0);
//         glBindTexture(GL_TEXTURE_2D, m_texture1);
//         glActiveTexture(GL_TEXTURE1);
//         glBindTexture(GL_TEXTURE_2D, m_texture2);

//         glBindVertexArray(m_vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//         glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//     }
// private:
//     Shader m_shader;
//     unsigned int m_texture1;
//     unsigned int m_texture2;
//     GLuint m_vao;
// };
// }

// DECLARE_MAIN(MyTexture)