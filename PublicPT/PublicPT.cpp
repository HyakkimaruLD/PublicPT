#include "UserInterface.h"

int main() {
    TaskManager taskManager;
    UserInterface ui(taskManager);

    ui.run();

    return 0;
}
