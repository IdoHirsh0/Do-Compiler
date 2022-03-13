#include "src/do/do.h"
#include "src/error_handler/error_handler.h"


int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        printf_red("Please specify source file.\n");
        return 1;
    }

    do_compile_file(argv[1]);

    return 0;
}
