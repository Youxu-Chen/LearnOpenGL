#ifndef __FRAMEWORK_H__
#define __FRAMEWORK_H__

#include <string>
#include "glad.h"
#include <GLFW/glfw3.h>

namespace CYXDemo {
class Framework {
public:
    Framework(int width = 800, int height = 600, std::string title = "Youxu Chen: OpenGL Demo Window");
    ~Framework();

    void Init();    // create window
    virtual void Startup(); // create shaders and link program
    virtual void Render() = 0;  // render
    void Run();             // init --> startup --> render
    void Exit();

    GLFWwindow *GetWindow() {
        return m_window;
    }

private:
    int m_width;
    int m_height;
    std::string m_title;
    GLFWwindow* m_window;
};
}


#define DECLARE_MAIN(APP)   \
int main() { \
    CYXDemo::APP *a = new CYXDemo::APP(); \
    a->Run(); \
    delete a; \
    return 0; \
}
#endif