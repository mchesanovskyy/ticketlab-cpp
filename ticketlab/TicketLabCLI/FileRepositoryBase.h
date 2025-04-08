#pragma once
#include <string>
#include <vector>

using namespace std;

/// <summary>
///  An abstract template class that provides general methods for working with files.
/// </summary>
/// <typeparam name="T">The type of entity the repository handles.</typeparam>
template <class T>
class FileRepositoryBase
{
public:
	virtual ~FileRepositoryBase() = default;

private:
	/// <summary>
	/// The name of the file used for storing or retrieving data.
	/// This value is set via the constructor.
	/// </summary>
	string _fileName;

protected:
	/// <summary>
	/// Constructor. 	
	/// Initializes the repository with the specified file name.
	/// </summary>
	FileRepositoryBase(string fileName) : _fileName(fileName) 
	{
	}

	/// <summary>
	/// A pure virtual method that must be overridden in a derived class.
	/// Responsible for converting an entity of type T to a string representation.
	/// </summary>	
	/// <param name="entity">A pointer to the entity to convert.</param>
	/// <returns>A string representation of the entity.</returns>
	virtual string ToString(T* entity) = 0;

	/// <summary>
	/// A pure virtual method that must be overridden in a derived class.
	/// Converts a string representation into an entity of type T.
	/// </summary>
	/// <param name="value">The string representation of the entity.</param>
	/// <returns>A pointer to the deserialized entity of type T.</returns>
	virtual T* ToEntity(string value) = 0;


	/// <summary>
	/// Appends a single entity to the end of the file.
	/// </summary>
	void AppendToFile(T* entity)
	{
		// Convert the entity to its string representation
		string entityLine = ToString(entity);

		// Open the file in append mode
		ofstream writer(_fileName, ios::app);

		if (!writer.is_open())
		{
			// If opening the file failed, throw a runtime error with a meaningful message
			throw runtime_error("Failed to open file: " + _fileName);
		}

		// Write the serialized entity followed by a newline
		writer << entityLine << '\n';

		// Always close the file after writing to free system resources
		writer.close();
	}


	/// <summary>
	/// Reads all records from the file and converts each line into an entity of type T.
	/// If the file does not exist, returns an empty list.
	/// </summary>
	vector<T*> ReadRecords()
	{
		// This vector will hold all the entities from the file.
		vector<T*> records; 

		// Open the file for reading using the stored file name.
		ifstream reader(_fileName); 

		if (!reader.is_open())
		{
			// If the file doesn't exist yet, just return an empty list.
			return records;
		}

		// This will hold each line read from the file.
		string line; 

		// Read the file line by line until the end
		while (getline(reader, line))
		{
			if (line.empty())
			{
				// Skip empty lines and go to the next line.
				continue; 
			}

			// Convert the line into an entity.
			T* entity = ToEntity(line);

			// Only add valid (non-null) entities.
			if (entity != nullptr) 
			{
				records.push_back(entity);
			}
		}

		// Always close the file when you're done to free system resources
		reader.close();

		// Return the vector of entity pointers
		return records; 
	}

};

