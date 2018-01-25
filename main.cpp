#include <iostream>
#include <GLFW/glfw3.h>

int main(void)
{
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
                return -1;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
        if (!window)
        {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
                /* Render here */
                glClear(GL_COLOR_BUFFER_BIT);

                glBegin(GL_LINE_LOOP);
                glColor3ub(255,0,0);    glVertex2d(-0.75,-0.75);
                glColor3ub(0,255,0);    glVertex2d(0,0.75);
                glColor3ub(0,0,255);    glVertex2d(0.75,-0.75);
                glEnd();

                glFlush();

                /* Swap front and back buffers */
                glfwSwapBuffers(window);

                /* Poll for and process events */
                glfwPollEvents();
        }

        glfwTerminate();
        return 0;
}
