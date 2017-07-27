/*
 * Voice Recognition Performance Test
 *
 * This software is not subject to copyright protection and is in the public domain.
 */

#include <cstring>

#include "nullimplvrpc11.h"

using namespace std;
using namespace VRPC;

NullImplVRPC11::NullImplVRPC11() {}

NullImplVRPC11::~NullImplVRPC11() {}

ReturnStatus
NullImplVRPC11::initialize(const std::string &configDir)
{
    this->counter = 0;
    return ReturnStatus(ReturnCode::Success);
}

ReturnStatus
NullImplVRPC11::createTemplate(
        const SoundRecord &soundrecord,
        TemplateRole role,
        std::vector<uint8_t> &templ)
{
    string blurb{"Nothing happens here...\n"};

    templ.resize(blurb.size());
    memcpy(templ.data(), blurb.c_str(), blurb.size());

    return ReturnStatus(ReturnCode::Success);
}

ReturnStatus
NullImplVRPC11::matchTemplates(
        const std::vector<uint8_t> &verifTemplate,
        const std::vector<uint8_t> &enrollTemplate,
        double &similarity)
{
    similarity = std::rand();
    return ReturnStatus(ReturnCode::Success);
}

std::shared_ptr<VerifInterface>
VerifInterface::getImplementation()
{
    return std::make_shared<NullImplVRPC11>();
}





