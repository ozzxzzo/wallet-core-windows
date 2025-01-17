// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <array>
#include <memory>
#include <vector>

#include "Cell.h"
//win
#ifdef _MSC_VER
#define _Nonnull
#endif

namespace TW::Everscale {

class CellSlice {
public:
    const Cell* _Nonnull cell;
    uint16_t dataOffset = 0;

    explicit CellSlice(const Cell* _Nonnull cell) noexcept
        : cell(cell) {}

    uint32_t getNextU32();
    Data getNextBytes(uint8_t bytes);

private:
    void require(uint16_t bits) const;
};

} // namespace TW::Everscale
