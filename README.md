# MyGameEngine


### modify submodule

#### imgui
- imgui.cpp
    ```c++
        for (int i = 0; window != NULL && i < window->DC.Layouts.Data.Size; i++)
        {
            ImGuiLayout* layout = (ImGuiLayout*)window->DC.Layouts.Data[i].val_p;
            IM_DELETE(layout);
        }
    ```
    






