/*
 * Voice Recognition Performance Test
 *
 * This software is not subject to copyright protection and is in the public domain.
 */

#ifndef NULLIMPLVRPC11_H_
#define NULLIMPLVRPC11_H_

#include "vrpc.h"

/*
 * Declare the implementation class of the VRPC VERIF (1:1) Interface
 */
namespace VRPC {
    class NullImplVRPC11 : public VRPC::VerifInterface {
public:

    NullImplVRPC11();
    ~NullImplVRPC11() override;

    ReturnStatus
    initialize(const std::string &configDir) override;

    ReturnStatus
    setGPU(uint8_t gpuNum) override;

    ReturnStatus
    createTemplate(
            const SoundRecord &soundrecord,
            TemplateRole role,
            std::vector<uint8_t> &templ) override;

    ReturnStatus
    matchTemplates(
            const std::vector<uint8_t> &verifTemplate,
            const std::vector<uint8_t> &enrollTemplate,
            double &similarity) override;

    static std::shared_ptr<VRPC::VerifInterface>
    getImplementation();

private:
    std::string configDir;
    uint8_t whichGPU;
    int counter;
    // Some other members
};
}

#endif /* NULLIMPLVRPC11_H_ */
