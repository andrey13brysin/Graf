#include"Obj.hpp"
#include<GLFW/glfw3.h>
#include<glad.h>

//Base Class Obj
void Obj3D::Draw()
{
    std::cout << "Draw" << std::endl;
}

//Class Triangle
Triangle::Triangle(GLfloat v[9], GLfloat c[9])
{
    int i = 0;
    for (i = 0; i < 9; i++)
    {
        vertex[i] = v[i];
        color[i] = c[i];
    }
    VAO = 0;
    VBO = 0;
    VBO_C = 0;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &VBO_C);


    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_C);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_C);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindVertexArray(0);
}
Triangle::~Triangle()
{

}
void Triangle::Draw()
{
    //std::cout << "Draw" << std::endl;
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

//Class Points

Points::Points(GLfloat* buf, GLfloat* c_buf, int vcount, GLint t)
{
    vertex = new GLfloat[vcount * 3];
    color = new GLfloat[vcount * 3];
    v_count = vcount;
 
    type = t;

    int i = 0;
    for (i; i < vcount * 3; i++)
    {
        vertex[i] = buf[i];
        color[i] = c_buf[i];
        std::cout << vertex[i]<< std::endl;
    }

    VBO = VBO_C = VAO = 0;

    glGenBuffers(1, &VBO);
    glGenBuffers(1, &VBO_C);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (vcount * 3), vertex, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_C);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * (vcount * 3), color, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glDisableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_C);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindVertexArray(0);
}

void Points::Draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, v_count);
    glBindVertexArray(0);
}