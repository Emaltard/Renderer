// ImGui - standalone example application for GLFW + OpenGL 3, using programmable pipeline
// If you are new to ImGui, see examples/README.txt and documentation at the top of imgui.cpp.
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan graphics context creation, etc.)
// (GL3W is a helper library to access OpenGL functions since there is no standard header to access modern OpenGL functions easily. Alternatives are GLEW, Glad, etc.)

#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <GL/glew.h>    // This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"

int main(int, char**)
{

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(1280, 720, "Renderer", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Setup ImGui binding
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui_ImplGlfwGL3_Init(window, true);
	//io.NavFlags |= ImGuiNavFlags_EnableKeyboard;  // Enable Keyboard Controls
	//io.NavFlags |= ImGuiNavFlags_EnableGamepad;   // Enable Gamepad Controls

	// Setup style
	ImGui::StyleColorsDark();
	ImGui::StyleColorsClassic();

	// Load Fonts
	// - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
	// - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
	// - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
	// - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
	// - Read 'misc/fonts/README.txt' for more instructions and details.
	// - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
	//io.Fonts->AddFontDefault();
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
	//ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
	//IM_ASSERT(font != NULL);

	bool show_demo_window = false;
	bool show_another_window = false;

	const double maxFPS = 60.0;
	const double maxPeriod = 1.0 / maxFPS;

	double lastTime = 0.0;


	while (!glfwWindowShouldClose(window))
	{
		double time = glfwGetTime();
		double deltaTime = time - lastTime;
		usleep(10);

		if( deltaTime >= maxPeriod ) {
			lastTime = time;
			// code here gets called with max FPS


			// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
			// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
			// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
			// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
			ImGui_ImplGlfwGL3_NewFrame();
			//
			// 1. Show a simple window.
			// Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets automatically appears in a window called "Debug".
			static float size = 1.0f;
			static float point_1_color[3] = {1, 0, 0};
			static float point_2_color[3] = {1, 0, 1};
			static float point_3_color[3] = {1, 1, 0};
			{
				ImGui::Text("Triangle Editor");      // Display some text (you can use a format string too)
				ImGui::SliderFloat("Size", &size, 0.0f, 1.0f); // Edit 1 float using a slider from 0.0f to 1.0f
				ImGui::ColorEdit3("Point 1 Color", point_1_color); // Edit 3 floats representing a color
				ImGui::ColorEdit3("Point 2 Color", point_2_color);
				ImGui::ColorEdit3("Point 3 Color", point_3_color);

				// ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our windows open/close state
				// ImGui::Checkbox("Another Window", &show_another_window);
        //
				//static int counter = 0;
				// if (ImGui::Button("Button"))       // Buttons return true when clicked (NB: most widgets return true when edited/activated)
				// 	counter++;
				// ImGui::SameLine();
				// ImGui::Text("counter = %d", counter);

				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			}

			// 2. Show another simple window. In most cases you will use an explicit Begin/End pair to name your windows.
			if (show_another_window)
			{
				ImGui::Begin("Another Window", &show_another_window);
				ImGui::Text("Hello from another window!");
				if (ImGui::Button("Close Me"))
					show_another_window = false;
				ImGui::End();
			}

			// 3. Show the ImGui demo window. Most of the sample code is in ImGui::ShowDemoWindow(). Read its code to learn more about Dear ImGui!
			if (show_demo_window)
			{
				ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver); // Normally user code doesn't need/want to call this because positions are saved in .ini file anyway. Here we just want to make the demo initial state a bit more friendly!
				ImGui::ShowDemoWindow(&show_demo_window);
			}


			float ratio;
			int width, height;
			glfwGetFramebufferSize(window, &width, &height);
			ratio = width / (float) height;
			glViewport(0, 0, width, height);
			glClear(GL_COLOR_BUFFER_BIT);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
			glBegin(GL_TRIANGLES);
			glColor3f(point_1_color[0], point_1_color[1], point_1_color[2]);
			glVertex3f(-0.6f*size, -0.4f*size, 0.f);
			glColor3f(point_2_color[0], point_2_color[1], point_2_color[2]);
			glVertex3f(0.6f*size, -0.4f*size, 0.f);
			glColor3f(point_3_color[0], point_3_color[1], point_3_color[2]);
			glVertex3f(0.f, 0.6f*size, 0.f);

			glEnd();

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	// // Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}
