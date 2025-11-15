cmake_minimum_required(VERSION 3.14)

project(ImGuiRaylibTemplateApp)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

include_directories("src"
                    "thirdParty/rlImGui"
                    "thirdParty/imgui-filebrowser"
                    "thirdParty/imgui"
                    "thirdParty/implot"
                   )


# We might need to add somekind of selector for the tempalte
set(IMGUI_SOURCES
    "thirdParty/imgui/imgui.cpp"
    "thirdParty/imgui/imgui_demo.cpp"
    "thirdParty/imgui/imgui_draw.cpp"
    "thirdParty/imgui/imgui_widgets.cpp"
    "thirdParty/imgui/imgui_tables.cpp"
    "thirdParty/imgui/backends/imgui_impl_opengl3.cpp"
)


set(RLIMGUI_SOURCES
    "thirdParty/rlImGui/rlImGui.cpp"
)

set(IMPLOT_SOURCES
    "thirdParty/implot/implot.cpp"
    "thirdParty/implot/implot_items.cpp"
)


set(SOURCES
    "src/main.cpp"
)

# Linking
add_executable(${PROJECT_NAME}
                ${SOURCES}
                ${IMGUI_SOURCES}
                ${RLIMGUI_SOURCES}
                ${IMPLOT_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
