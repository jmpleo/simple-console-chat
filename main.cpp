#include "chatman.h"
#include "dataman.h"

int main()
{
    ChatManager(new DataManager).AuthPage();
    return 0;
}
