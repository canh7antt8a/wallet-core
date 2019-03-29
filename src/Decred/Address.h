// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "../PublicKey.h"

#include <array>
#include <string>

namespace TW {
namespace Decred {

class Address {
  public:
    /// Public key hash.
    std::array<byte, 20> keyhash;

    /// Determines whether a string makes a valid  address.
    static bool isValid(const std::string& string) noexcept;

    /// Initializes an address with a string representation.
    explicit Address(const std::string& string);

    /// Initializes an address with a public key.
    explicit Address(const PublicKey& publicKey);

    /// Returns a string representation of the address.
    std::string string() const;

  private:
    static std::array<byte, 4> checksum(const std::array<byte, 20>& keyhash);
};

static inline bool operator==(const Address& lhs, const Address& rhs) {
    return lhs.keyhash == rhs.keyhash;
}

} // namespace Decred
} // namespace TW

/// Wrapper for C interface.
struct TWDecredAddress {
    TW::Decred::Address impl;
};