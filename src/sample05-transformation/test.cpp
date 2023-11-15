#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
using namespace std;

// (1,1) vector
// translate (0.5, -0.5)
// result --> (1.5, 0.5)

int main() {
    glm::vec4 vec(1.0f, 1.0f, 0.0f, 1.0f);
    glm::mat4 trans = glm::mat4(1.0f);
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << trans[i][j] << "\t";
        }
        cout << endl;
    }

    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << trans[j][i] << "\t";
        }
        cout << endl;
    }
    vec = trans * vec;
    std::cout << vec.x << vec.y << vec.z << std::endl;
}