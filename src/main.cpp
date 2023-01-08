#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <iostream>

int main() {
  // Initialisez GLFW
  if (!glfwInit()) {
    std::cerr << "Error: failed to initialize GLFW" << std::endl;
    return 1;
  }

  // Créez une fenêtre GLFW
  GLFWwindow* window = glfwCreateWindow(640, 480, "My Project", nullptr, nullptr);
  if (!window) {
    std::cerr << "Error: failed to create GLFW window" << std::endl;
    glfwTerminate();
    return 1;
  }

  // Faites de la fenêtre la cible de contexte OpenGL
  glfwMakeContextCurrent(window);

  // Initialisez GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Error: failed to initialize GLAD" << std::endl;
    return 1;
  }

  // Initialisez Dear ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
  //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking

  //io.ConfigViewportsNoAutoMerge = true;
  //io.ConfigViewportsNoTaskBarIcon = true;

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();
  //ImGui::StyleColorsClassic();

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  // Créez un triangle avec GLM
  glm::vec3 triangle[] = {
    glm::vec3(-1.0f, -1.0f, 0.0f),
    glm::vec3( 1.0f, -1.0f, 0.0f),
    glm::vec3( 0.0f,  1.0f, 0.0f),
  };

  bool show_demo_window = true;
  

  // Boucle principale
  while (!glfwWindowShouldClose(window)) {
    // Nettoyez l'écran
    glClear(GL_COLOR_BUFFER_BIT);

    // Démarrez la frame ImGui
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::ShowDemoWindow(&show_demo_window);

    // Affichez un menu contextuel
    ImGui::Begin("Menu");
    ImGui::Text("Hello, world!");
    
    ImGui::End();

  

    // Affichez la frame ImGui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Échangez les buffers de fenêtre
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Nettoyez ImGui
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  // Nettoyez GLFW
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}