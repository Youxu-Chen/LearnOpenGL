#include "framework.h"

using namespace CYXDemo;

namespace CYXDemo {
    class Window : public Framework {
        void Render() {
            glClearColor(0.2f, 0.3f, 0.4f, 1);
            glClear(GL_COLOR_BUFFER_BIT);
        }
    };
}

DECLARE_MAIN(Window)