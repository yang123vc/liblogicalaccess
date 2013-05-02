/**
 * \file aes_symmetric_key.cpp
 * \author Julien KAUFFMANN <julien.kauffmann@islog.eu>
 * \author Maxime CHAMLEY <maxime.chamley@islog.eu>
 * \brief AES symmetric key class.
 */

#include "logicalaccess/crypto/aes_symmetric_key.h"
#include "logicalaccess/crypto/sha.h"

namespace LOGICALACCESS
{
	namespace openssl
	{
		AESSymmetricKey AESSymmetricKey::createRandom(size_t size)
		{
			return AESSymmetricKey(size);
		}

		AESSymmetricKey AESSymmetricKey::createFromData(const std::vector<unsigned char>& data)
		{
			return AESSymmetricKey(data);
		}

		AESSymmetricKey AESSymmetricKey::createFromPassphrase(const std::string& passphrase)
		{
			return createFromData(SHA256Hash(passphrase));
		}

		AESSymmetricKey::AESSymmetricKey(size_t size) :
			SymmetricKey(size)
		{
		}

		AESSymmetricKey::AESSymmetricKey(const std::vector<unsigned char>& _data) :
			SymmetricKey(_data)
		{
		}
	}
}
