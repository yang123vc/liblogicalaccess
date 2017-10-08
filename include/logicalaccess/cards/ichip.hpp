/**
 * \file ichip.hpp
 * \author Maxime C. <maxime-dev@islog.com>
 * \brief IChip descriptor.
 */

#ifndef LOGICALACCESS_ICHIP_HPP
#define LOGICALACCESS_ICHIP_HPP

#include <memory>
#include <vector>
#include "logicalaccess/lla_fwd.hpp"
#include "logicalaccess/logicalaccess_api.hpp"
#include <logicalaccess/services/cardservice.hpp>

namespace logicalaccess
{
    /**
     * \brief The base abstract chip class for all chip.
     */
    class LIBLOGICALACCESS_API IChip
    {
    public:
        /**
         * \brief Get the card type of the chip.
         * \return The chip's card type.
         */
        virtual const std::string& getCardType() const = 0;

        /**
         * \brief Get the generic card type.
         * \return The generic card type.
         */
        virtual std::string getGenericCardType() const = 0;

        /**
         * \brief Get the commands.
         * \return The commands.
         */
        virtual std::shared_ptr<Commands> getCommands() const = 0;

        /**
         * \brief Get the chip identifier.
         * \return The chip identifier.
         */
        virtual const std::vector<unsigned char> getChipIdentifier() const = 0;

        /**
         * \brief Get a card service for this chip.
         * \param serviceType The card service type.
         * \return The card service.
         */
        virtual std::shared_ptr<CardService> getService(CardServiceType serviceType) = 0;
    };
}

#endif /* LOGICALACCESS_ICHIP_HPP */