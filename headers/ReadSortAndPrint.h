/*!
 * @file
 * @brief contains one function which reads file, sortes it and prints in stdin
 */

#pragma once
#include <headers/Text.h>
#include <headers/TextSort.h>

/*!
 * @brief reads file, sortes it and prints in stdin
 * Creates Text object which reads file,
 * uses functions from TextSort to sort it
 * prints it sorted then backsorted and
 * then raw.
 *
 * @param filename file name to operate with
 */
void ReadSortAndPrint(const std::string& filename);
