#include <diabloui.h>

int CALLBACK WinMain (
  _In_ HINSTANCE hInstance,
  _In_ HINSTANCE hPrevInstance,
  _In_ LPSTR     lpCmdLine,
  _In_ int       nCmdShow
) {
    UiInitialize();
    UiTitleDialog(7);
    int dlgResult = 0;
    while (dlgResult != 5) {
        UiMainMenuDialog("test", &dlgResult, nullptr, 30);
    }
    UiDestroy();
    return 0;
}
