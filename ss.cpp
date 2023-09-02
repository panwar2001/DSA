#include <windows.h>
#include <iostream>

using namespace std;

int main() {
  // Get a device context for the entire screen.
  HDC hdcScreen = GetDC(NULL);

  // Create a compatible device context.
  HDC hdcMem = CreateCompatibleDC(hdcScreen);

  // Create a compatible bitmap.
  HBITMAP bmp = CreateCompatibleBitmap(hdcScreen, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));

  // Select the compatible bitmap into the compatible device context.
  SelectObject(hdcMem, bmp);

  // Copy the screen to the compatible bitmap.
  BitBlt(hdcMem, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), hdcScreen, 0, 0, SRCCOPY);

  // Save the compatible bitmap to a file.
  SaveDCSnapshot(bmp, "screenshot.bmp");

  // Delete the compatible bitmap.
  DeleteObject(bmp);

  // Delete the compatible device context.
  DeleteDC(hdcMem);

  // Release the device context for the entire screen.
  ReleaseDC(NULL, hdcScreen);

  return 0;
}
