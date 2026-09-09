#ifndef PLATFORM_H
#define PLATFORM_H

int platformInit();
int platformRunning();
void platformPollEvents();
void platformPresent();
void platformShutdown();

#endif