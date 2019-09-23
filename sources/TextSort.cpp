#include <headers/TextSort.h>



namespace text {

void SortTextLexicographically(text::Text& text) {
  std::sort(text.Begin(), text.End(),
            privatefunctions::StringLexicographicallyCmp);
}

void SortTextBackLexicographically(text::Text& text) {
  std::sort(text.Begin(), text.End(),
            privatefunctions::StringBackLexicographicallyCmp);
}

namespace privatefunctions {

bool StringLexicographicallyCmp(const std::string_view& lhvalue,
                                const std::string_view& rhvalue) {
  return StringIteratorCmp(lhvalue.cbegin(),
                           lhvalue.cend(),
                           rhvalue.cbegin(),
                           rhvalue.cend());
}

bool StringBackLexicographicallyCmp(const std::string_view& lhvalue,
                                    const std::string_view& rhvalue) {
  return StringIteratorCmp(lhvalue.crbegin(),
                           lhvalue.crend(),
                           rhvalue.crbegin(),
                           rhvalue.crend());
}

template<class Iter>
bool StringIteratorCmp(Iter left_it,
                       Iter left_end,
                       Iter right_it,
                       Iter right_end) {
  for ( ;
      left_it != left_end &&
      right_it != right_end;
      ++left_it, ++right_it) {
    while (!IsComparable(*left_it)) {
      ++left_it;
    }

    while (!IsComparable(*right_it)) {
      ++right_it;
    }

    if        (std::tolower(*left_it) < std::tolower(*right_it)) {
      return true;
    } else if (std::tolower(*left_it) > std::tolower(*right_it)) {
      return false;
    }
  }

  return right_it != right_end;
}

inline bool IsComparable(char letter) {
  return std::isalpha(letter) || std::isdigit(letter);
}

} // namespace privatefunctions

} // namespace text
