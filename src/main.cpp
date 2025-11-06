#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include <imfilebrowser.h>
#include <implot.h>

#include <cmath>
#include <iostream>
#include <stdio.h>

#define BG_GRAY {30, 30, 30, 255}

int main(int argc, char *argv[])
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(600, 400, "ImGui・Raylib - Template App");

    SetTargetFPS(60);

    rlImGuiSetup(true); // Setup ImGui
    ImPlot::CreateContext();


    // File dialog:
    ImGui::FileBrowser fileDialog;
    fileDialog.SetTitle("title");
    fileDialog.SetTypeFilters({".h", ".cpp"});

    // Plots
    int bar_data[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int data_points = 1000;
    float x_o = 0.0;
    float dx = 0.01;
    float *x_data = (float *)malloc(data_points * sizeof(float));
    float *y_data = (float *)malloc(data_points * sizeof(float));

    if (x_data == NULL || y_data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < data_points; i++)
    {
        x_data[i] = x_o + i * dx;
        y_data[i] = sinf(x_data[i]);
    }

    while (true)
    {
        BeginDrawing();
        ClearBackground(BG_GRAY);
        rlImGuiBegin();

        // File dialog
        if (ImGui::Begin("Dummy window N-1"))
        {
            // open file dialog when user clicks this button
            if (ImGui::Button("open file dialog"))
                fileDialog.Open();
        }
        ImGui::End();

        fileDialog.Display();

        if (fileDialog.HasSelected())
        {
            std::cout << "Selected filename" << fileDialog.GetSelected().string() << std::endl;
            fileDialog.ClearSelected();
        }

        ImGui::Begin("My Window");
        if (ImPlot::BeginPlot("My Plot"))
        {
            ImPlot::PlotBars("My Bar Plot", bar_data, 11);
            ImPlot::PlotLine("My Line Plot", x_data, y_data, 1000);
            ImPlot::EndPlot();
        }
        ImGui::End();

        rlImGuiEnd();
        EndDrawing();
    }

    ImPlot::DestroyContext();
    rlImGuiShutdown();
    CloseWindow();

    return 0;
}
