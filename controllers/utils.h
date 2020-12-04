#include <time.h>
#include <thread>
#include <chrono>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_ELEMENT 1000

const char *detectOS()
{
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#elif __unix || __unix__
    return "Unix";
#else
    return "Other";
#endif
}

const char *printCurrentTime()
{
    time_t current;
    current = time(NULL);
    return ctime(&current);
}

void sleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void clearscreen()
{
    system("cls||clear");
}

unsigned long DJB2(char *str)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % MAX_ELEMENT;
}

void center_print(const char *s, int width)
{
    int length = strlen(s);
    int i;
    for (i = 0; i <= (width - length) / 2; i++)
    {
        fputs(" ", stdout);
    }
    fputs(s, stdout);
    i += length;
    for (; i <= width; i++)
    {
        fputs(" ", stdout);
    }
}