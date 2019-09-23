/*!
 * @file
 * @brief header with functions which sorts strings in Text object
 */

#pragma once
#include <string_view>
#include <cctype>
#include <algorithm>
#include <headers/Text.h>

namespace text {

/*!
 * @brief sorts text strings lexicographically
 * @param text to be sorted
 */
void SortTextLexicographically(text::Text& text);

/*!
 * @brief sorts text strings back lexicographically
 * @param text to be sorted
 */
void SortTextBackLexicographically(text::Text& text);

namespace privatefunctions {

/*!
 * @brief compares two strings lexicographically
 * @param lhvalue
 * @param rhvalue
 * @return lhvalue < rhvalue
 */
bool StringLexicographicallyCmp(const std::string_view& lhvalue,
                                       const std::string_view& rhvalue);

/*!
 * @brief compares two strings back lexicographically
 * @param lhvalue
 * @param rhvalue
 * @return lhvalue < rhvalue
 */
bool StringBackLexicographicallyCmp(const std::string_view& lhvalue,
                                           const std::string_view& rhvalue);

/*!
 * @brief compares strings' iterators
 * @tparam Iter iterator type
 * @param left_it
 * @param left_end
 * @param right_it
 * @param right_end
 * @return left < right
 */
template<class Iter>
bool StringIteratorCmp(Iter left_it,
                              Iter left_end,
                              Iter right_it,
                              Iter right_end);

/*!
 * @param letter
 * @return is digit or letter
 */
static inline bool IsComparable(char letter);

} // namespace privatefunctions

} // namespace textsort