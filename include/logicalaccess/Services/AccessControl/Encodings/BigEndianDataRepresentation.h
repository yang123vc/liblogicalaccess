/**
 * \file BigEndianDataRepresentation.h
 * \author Arnaud HUMILIER <arnaud.humilier@islog.eu>, Maxime CHAMLEY <maxime.chamley@islog.eu>
 * \brief BigEndianDataRepresentation.
 */

#ifndef LOGICALACCESS_BIGENDIANDATAREPRESENTATION_H
#define LOGICALACCESS_BIGENDIANDATAREPRESENTATION_H	

#include "logicalaccess/Services/AccessControl/Encodings/DataRepresentation.h"
#include "logicalaccess/Services/AccessControl/Encodings/Encoding.h"

#include <string>

using std::string;

namespace LOGICALACCESS
{
	/**
	 * \brief A Big Endian data representation class.
	 */
	class LIBLOGICALACCESS_API BigEndianDataRepresentation : public DataRepresentation
	{
		public:
			/**
			 * \brief Constructor.
			 *
			 * Create a BigEndianDataRepresentation representation.
			 */
			BigEndianDataRepresentation();

			/**
			 * \brief Destructor.
			 *
			 * Release the BigEndianDataRepresentation representation.
			 */
			~BigEndianDataRepresentation();

			/**
			 * \brief Get the representation name
			 * \return The representation name
			 */
			virtual string getName() const;

			/**
			 * \brief Get the encoder type.
			 * \return The encoder type.
			 */
			virtual EncodingType getType() const;

			/**
			 * \brief Convert data to the encoding type
			 * \param data Data to convert
			 * \param dataLengthBytes Length of data to convert in bytes
			 * \param dataLengthBits Length of data to convert in bits
			 * \param convertedData Data after conversion
			 * \param convertedLengthBytes Length of "convertedData" in bytes			 
			 * \return Length after conversion in bits
			 */
			virtual unsigned int convertNumeric(const void* data, size_t dataLengthBytes, unsigned int dataLengthBits, void* convertedData, size_t convertedLengthBytes);

			/**
			 * \brief Convert binary data to the encoding type
			 * \param data Data to convert
			 * \param dataLengthBytes Length of data to convert in bytes
			 * \param dataLengthBits Length of data to convert in bits
			 * \param convertedData Data after conversion
			 * \param convertedLengthBytes Length of "convertedData" in bytes			 
			 * \return Length after conversion in bits
			 */
			virtual unsigned int convertBinary(const void* data, size_t dataLengthBytes, unsigned int dataLengthBits, void* convertedData, size_t convertedLengthBytes);

			/**
			 * \brief Get the length after conversation for a given base length in bits
			 * \param lengthBits The unconverted length in bits
			 * \return The converted length in bits
			 */
			virtual unsigned int convertLength(unsigned int lengthBits);

			/**
			 * \brief Revert data
			 * \param data Data to revert
			 * \param dataLengthBytes Length of data to convert in bytes
			 * \param dataLengthBits Length of data to convert in bits
			 * \param convertedData Data after reversion
			 * \param convertedLengthBytes Length of "convertedData"
			 * \return Length after reversion in bits
			 */
			virtual unsigned int revertNumeric(const void* data, size_t dataLengthBytes, unsigned int dataLengthBits, void* convertedData, size_t convertedLengthBytes);

			/**
			 * \brief Revert binary data
			 * \param data Data to revert
			 * \param dataLengthBytes Length of data to convert in bytes
			 * \param dataLengthBits Length of data to convert in bits
			 * \param convertedData Data after reversion
			 * \param convertedLengthBytes Length of "convertedData"
			 * \return Length after reversion in bits
			 */
			virtual unsigned int revertBinary(const void* data, size_t dataLengthBytes, unsigned int dataLengthBits, void* convertedData, size_t convertedLengthBytes);

		protected:

	};	
}

#endif /* LOGICALACCESS_BIGENDIANDATAREPRESENTATION_H */
