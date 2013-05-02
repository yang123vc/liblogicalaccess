/**
 * \file ISO14443BReaderCommunication.h
 * \author Maxime CHAMLEY <maxime.chamley@islog.eu>
 * \brief ISO14443-3B Reader communication. 
 */

#ifndef LOGICALACCESS_ISO14443BREADERCOMMUNICATION_H
#define LOGICALACCESS_ISO14443BREADERCOMMUNICATION_H

#include "logicalaccess/ReaderProviders/ReaderCommunication.h"

#include <string>
#include <vector>
using std::string;
using std::vector;

#include "logicalaccess/logs.h"

namespace LOGICALACCESS
{
	/**
	 * \brief A ISO14443-3B reader communication base class.
	 */
	class LIBLOGICALACCESS_API ISO14443BReaderCommunication : public virtual ReaderCommunication
	{
		public:

			/**
			 * \brief Send a REQB command from the PCD to the PICC.
			 * \param afi The AFI value.
			 * \return The ATQB PICC result.
			 */
			virtual std::vector<unsigned char> requestB(unsigned char afi = 0x00) = 0;

			/**
			 * \brief Send a HLTB command from the PCD to the PICC.
			 */
			virtual void haltB() = 0;

			/**
			 * \brief Send a attrib command from the PCD to the PICC.
			 */
			virtual void attrib() = 0;

			/**
			 * \brief Manage collision.
			 * \param afi The AFI value.
			 * \return The chip UID.
			 */
			virtual std::vector<unsigned char> anticollisionB(unsigned char afi = 0x00) = 0;
	};

}

#endif /* LOGICALACCESS_ISO14443BREADERCOMMUNICATION_H */

