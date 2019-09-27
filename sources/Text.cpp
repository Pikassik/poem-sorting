#include <headers/Text.h>

namespace text {

void Text::ReadText(const std::string& filename) {
  text_ = nullptr;

  std::FILE* text_file = std::fopen(filename.data(), "r");

  assert(text_file != nullptr);

  SetFileSize(text_file);

  text_ = std::make_unique<char[]>(text_size_ + 1);
  std::fread(text_.get(), sizeof(char), text_size_, text_file);

  int is_eof = std::fclose(text_file);

  assert(is_eof != EOF);

  AddNewLineToEnd();
  InitializeStrings(StringsCount());

}

void Text::PrintText() const {
  for (const auto& poem_string: strings_) {
    if (!poem_string.empty()) {
      std::puts(poem_string.data());
    }
  }
}

void Text::PrintRawText() const {
  for (size_t i = 0; i < text_size_; ++i) {
    std::putchar(text_[i] == '\0' ? '\n' : text_[i]);
  }
}

std::vector<std::string_view>::iterator Text::Begin() {
  return strings_.begin();
}

std::vector<std::string_view>::iterator Text::End() {
  return strings_.end();
}

void Text::SetFileSize(std::FILE* text_file) {
  assert(text_file != nullptr);

  std::fseek(text_file, 0, SEEK_END);
  text_size_ = std::ftell(text_file);
  std::fseek(text_file, 0, SEEK_SET);
}

void Text::AddNewLineToEnd() {
  if (text_[text_size_ - 1] != '\n') {
    ++text_size_;
    text_[text_size_ - 1] = '\n';
  }
}

size_t Text::StringsCount() {
  size_t strings_count = 0;
  for (size_t i = 0; i < text_size_; ++i) {
    if (text_[i] == '\n') {
      text_[i] = '\0';
      ++strings_count;
    }
  }

  return strings_count;
}

void Text::InitializeStrings(size_t strings_count) {
  strings_.reserve(strings_count);
  char* current_string_beginning = text_.get();
  for (size_t i = 0; i < text_size_; ++i) {
    if (text_[i] == '\0') {
      strings_.emplace_back(current_string_beginning,
                            text_.get() + i - current_string_beginning);
      current_string_beginning = text_.get() + i + 1;
    }
  }
}

} // namespace text