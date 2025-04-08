#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/// <summary>
/// A utility namespace that provides common string operations
/// </summary>
namespace str_helpers
{
	/// <summary>
    /// Splits the input string into a vector of substrings using the specified delimiter character.
    /// </summary>
    /// <param name="value">The input string to split.</param>
    /// <param name="delimiter">The character used to split the string.</param>
    /// <returns>A vector of substrings.</returns>
	inline vector<string> Split(const string& value, char delimiter)
	{
		stringstream ss(value);
		string item;
		vector<string> parts;
		while (getline(ss, item, delimiter))
		{
			parts.push_back(item);
		}
		return parts;
	}

	/// <summary>
	/// Compares two strings for equality, ignoring case differences.
	/// </summary>
	/// <param name="a">The first string to compare.</param>
	/// <param name="b">The second string to compare.</param>
	/// <returns>'True' if the strings are equal ignoring case; otherwise, 'False'.</returns>
	inline bool IsEqualsIgnoreCase(const string& a, const string& b)
	{
		return equal(a.begin(), a.end(), b.begin(),
			b.end(), [](char a, char b)
			{
				return tolower(a) == tolower(b);
			});
	}

	/// <summary>
	/// Joins an array of strings into a single string, separated by the specified delimiter.
	/// </summary>
	/// <typeparam name="size">The size of the array.</typeparam>
	/// <param name="parts">The array of strings to join.</param>
	/// <param name="delimiter">The character to insert between each string.</param>
	/// <returns>A single string containing the joined parts.</returns>
	template <std::size_t size>
	string Join(const string(&parts)[size], char delimiter)
	{
		stringstream ss;
		for (size_t i = 0; i < size; i++)
		{
			ss << parts[i];
			if ((i + 1) < size) {
				ss << delimiter;
			}
		}
		return ss.str();
	}

	/// <summary>
	/// Replaces all occurrences of a character in a string with another character.
	/// </summary>
	/// <param name="str">The original string to modify.</param>
	/// <param name="old_value">The character to be replaced.</param>
	/// <param name="new_value">The character to replace with.</param>
	/// <returns>A new string with the specified replacements.</returns>
	inline string Replace(std::string str, char old_value, char new_value)
	{
		std::replace(str.begin(), str.end(), old_value, new_value);
		return str;
	}
};

