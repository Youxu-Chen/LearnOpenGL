// #include "framework.h"

// #include <iostream>
// #include <math.h>

// namespace CYXDemo {
// class MyShader : public Framework {
//     void Startup() {
//         const char *vertexShaderSource = "#version 330 core\n"
//         "layout (location = 0) in vec3 aPos;\n"
//         "layout (location = 1) in vec3 aColor;\n"
//         "out vec4 ourColor;\n"
//         "void main()\n"
//         "{\n"
//         "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//         "   ourColor = vec4(aColor, 1.0);\n"
//         "}\0";
//     const char *fragmentShaderSource = "#version 330 core\n"
//         "out vec4 FragColor;\n"
//         "in vec4 ourColor;\n"
//         "void main()\n"
//         "{\n"
//         "   FragColor = ourColor;\n"
//         "}\n\0";
        
//         unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//         glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//         glCompileShader(vertexShader);
//         // check for shader compile errors
//         int success;
//         char infoLog[512];
//         glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//         if (!success)
//         {
//             glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//             std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//         }
//         // fragment shader
//         unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//         glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//         glCompileShader(fragmentShader);
//         // check for shader compile errors
//         glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//         if (!success)
//         {
//             glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//             std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//         }
//         // link shaders
//         m_program = glCreateProgram();
//         glAttachShader(m_program, vertexShader);
//         glAttachShader(m_program, fragmentShader);
//         glLinkProgram(m_program);
//         // check for linking errors
//         glGetProgramiv(m_program, GL_LINK_STATUS, &success);
//         if (!success) {
//             glGetProgramInfoLog(m_program, 512, NULL, infoLog);
//             std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//         }
//         glDeleteShader(vertexShader);
//         glDeleteShader(fragmentShader);

//         float vertices[] = {
//             // 位置              // 颜色
//             0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
//             -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
//             0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
//         };

//         unsigned int VBO;
//         glGenVertexArrays(1, &m_vao);
//         glGenBuffers(1, &VBO);
//         // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//         glBindVertexArray(m_vao);

//         glBindBuffer(GL_ARRAY_BUFFER, VBO);
//         glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//         glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//         glEnableVertexAttribArray(0);
//         glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)(3* sizeof(float)));
//         glEnableVertexAttribArray(1);

//         // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//         glBindBuffer(GL_ARRAY_BUFFER, 0); 

//         // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//         // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//         // glBindVertexArray(0); 
//     }

//     void Render() {
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         float timeValue = glfwGetTime();
//         float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
//         int vertexColorLocation = glGetUniformLocation(m_program, "ourColor");
        

//         // draw our first triangle
//         glUseProgram(m_program);
//         glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//         glBindVertexArray(m_vao); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//         glDrawArrays(GL_TRIANGLES, 0, 3);
//     }

// private:
//     GLuint m_program;
//     GLuint m_vao;
// };
// }

// DECLARE_MAIN(MyShader)