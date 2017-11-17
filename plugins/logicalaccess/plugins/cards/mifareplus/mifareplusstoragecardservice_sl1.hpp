//
// Created by xaqq on 7/2/15.
//

#ifndef LIBLOGICALACCESS_MIFAREPLSSTORAGECARDSERVICE_SL1_H
#define LIBLOGICALACCESS_MIFAREPLSSTORAGECARDSERVICE_SL1_H


#include <logicalaccess/plugins/cards/mifare/mifarestoragecardservice.hpp>

namespace logicalaccess
{
#define STORAGECARDSERVICE_MIFARE_PLUS "MifarePlusStorageSL1"

class LIBLOGICALACCESS_API MifarePlusStorageSL1CardService
    : public MifareStorageCardService
{

  public:
    explicit MifarePlusStorageSL1CardService(std::shared_ptr<Chip> chip);

    std::string getCSType() override { return STORAGECARDSERVICE_MIFARE_PLUS; }

    void erase(std::shared_ptr<Location> location,
               std::shared_ptr<AccessInfo> aiToUse) override;

    void writeData(std::shared_ptr<Location> location,
                   std::shared_ptr<AccessInfo> aiToUse,
                   std::shared_ptr<AccessInfo> aiToWrite, const ByteVector &data,
                   CardBehavior behaviorFlags) override;

    ByteVector readData(std::shared_ptr<Location> location,
                        std::shared_ptr<AccessInfo> aiToUse, size_t length,
                        CardBehavior behaviorFlags) override;

    ByteVector readDataHeader(std::shared_ptr<Location> location,
                              std::shared_ptr<AccessInfo> aiToUse) override;

  private:
    void authenticate_if_needed(std::shared_ptr<AccessInfo>);

    /**
     * We perform AES authentication at most once, for performance
     * reason.
     */
    bool has_been_authenticated_;
};
}

#endif // LIBLOGICALACCESS_MIFAREPLSSTORAGECARDSERVICE_SL1_H
