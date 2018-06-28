/** @file  */
#ifndef PROJEKT_MODE_H
#define PROJEKT_MODE_H

#include <stdio.h>
#include <string.h>

/**
 * Shows help
 */
void help();

/**
 * Return game mode
 * @param argument -argument from command line
 * @return 0 - if unknown or wrong argument
 *         1 - if game of life
 *         2 - ant game
 */
unsigned int mode(const char* argument);

#endif //PROJEKT_MODE_H
