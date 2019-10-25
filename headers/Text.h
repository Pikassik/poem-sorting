/*!
 * @file
 * @brief Class for reading text from file, parsing it to strings and owning
 */

#pragma once
#include <cstdio>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <cassert>

class TestText;
class TestTextSort;

namespace text {


/*!
 * @brief Class for reading text from file, parsing it to strings and owning
 */

class Text {
  friend TestText;
  friend TestTextSort;

 public:

  /*!
   * @brief reads file
   * Opens file, allocates memory for chars, reads into ram
   * and parses into strings.
   * @param filename file name to read
   */
  void ReadText(const std::string& filename);

  /*!
   * @brief prints text from buffer to stdout
   */
  void PrintText() const;

  /*!
   * @brief prints raw file content
   */
  void PrintRawText() const;


  const std::string_view& Data(size_t index) const;

  size_t Size() const;

  /*!
   * @return iterator to begin of string buffer
   */
  std::vector<std::string_view>::iterator Begin();

  /*!
   * @return iterator to end of string buffer
   */
  std::vector<std::string_view>::iterator End();

 private:

  /*!
   * @brief calculates file size and sets it to the poem_size_
   * @param text_file
   */
  void SetFileSize(std::FILE* text_file);

  /*!
   * @brief adds new line symbol to read file if it absent
   */
  void AddNewLineToEnd();

  /*!
   * Calculates count of strings in read file and replaces '\n' to '\0' symbols
   * @return count of strings in file
   */
  size_t StringsCount();

  /*!
   * @brief iterates over an read file and initializes strings
   * @param strings_count to allocate memory
   */
  void InitializeStrings(size_t strings_count);

  std::vector<std::string_view> strings_;
  size_t text_size_ = 0;
  std::unique_ptr<char[]> text_;
};

} // namespace text