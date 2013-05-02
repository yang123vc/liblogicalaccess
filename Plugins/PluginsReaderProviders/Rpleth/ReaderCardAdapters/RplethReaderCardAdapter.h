/**
 * \file RplethReaderCardAdapter.h
 * \author Maxime CHAMLEY <maxime.chamley@islog.eu>
 * \brief Default Rpleth reader/card adapter. 
 */

#ifndef LOGICALACCESS_DEFAULTRPLETHREADERCARDADAPTER_H
#define LOGICALACCESS_DEFAULTRPLETHREADERCARDADAPTER_H

#include "logicalaccess/Cards/ReaderCardAdapter.h"
#include "../RplethReaderUnit.h"

#include <string>
#include <vector>
using std::string;
using std::vector;

#include "logicalaccess/logs.h"

namespace LOGICALACCESS
{	
	/**
	 * \brief A default Rpleth reader/card adapter class.
	 */
	class LIBLOGICALACCESS_API RplethReaderCardAdapter : public ReaderCardAdapter
	{
		public:

			/**
			 * \brief Constructor.
			 */
			RplethReaderCardAdapter();

			/**
			 * \brief Destructor.
			 */
			virtual ~RplethReaderCardAdapter();

			/**
			 * \brief Send a command to the reader.
			 * \param command The command buffer.			 
			 * \param timeout The command timeout.
			 * \return The result of the command.
			 */
			std::vector<unsigned char> sendCommand(const std::vector<unsigned char>& command, long int timeout = 2000);
			
			/**
			 * \brief Receive the reader answer.
			 * \param command The sand command buffer.		 
			 * \param timeout The answer timeout.
			 * \return The answer.
			 */
			std::vector<unsigned char> receiveAnwser(const std::vector<unsigned char>& command, long int timeout = 2000);
			
			/**
			 * \brief Get the Rpleth reader unit.
			 * \return The Rpleth reader unit.
			 */
			boost::shared_ptr<RplethReaderUnit> getRplethReaderUnit() const { return boost::dynamic_pointer_cast<RplethReaderUnit>(getReaderUnit()); };			

			

		protected:

			/**
			 * \brief Calculate command checksum.
			 * \param data The data to calculate checksum
			 * \return The checksum.
			 */
			unsigned char calcChecksum(const std::vector<unsigned char>& data);
			
			/**
			 * \brief Handle a answer and give the associated data buffer.
			 * \param cmdbuf The answer buffer.
			 * \return The data buffer.
			 */
			std::vector<unsigned char> handleAnswerBuffer(const std::vector<unsigned char>& cmdbuf, std::vector<unsigned char>& ansbuf);		
	};

}

#endif /* LOGICALACCESS_DEFAULTRPLETHREADERCARDADAPTER_H */

 
