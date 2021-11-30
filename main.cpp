#include <FEHLCD.h>
#include <FEHFile.h>
#include <FEHUtility.h>

/*
 * Entry point to the application
 */
int main() {
    // Clear background
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();

    LCD.WriteLine("Hello World!");
    Sleep(3.0);

    while (1) {
        LCD.Update();
        // Never end
    }
    return 0;
}