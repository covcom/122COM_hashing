/* credit to rosettacode for the original code, it has been modified to meet the 
  lab requirements since iterators and uint_fast32_t havn't been introduced yet */

#if !defined(CRC32_H)
#define CRC32_H

#include <algorithm>
#include <array>
#include <cstdint>
#include <numeric>
#include <sstream>
 
// These headers are only needed for main(), to demonstrate.
#include <string>
 
// Generates a lookup table for the checksums of all 8-bit values.
std::array<std::uint_fast32_t, 256> generate_crc_lookup_table() noexcept
{
  auto const reversed_polynomial = std::uint_fast32_t{0xEDB88320uL};
 
  // This is a function object that calculates the checksum for a value,
  // then increments the value, starting from zero.
  struct byte_checksum
  {
    std::uint_fast32_t operator()() noexcept
    {
      auto checksum = static_cast<std::uint_fast32_t>(n++);
 
      for (auto i = 0; i < 8; ++i)
        checksum = (checksum >> 1) ^ ((checksum & 0x1u) ? reversed_polynomial : 0);
 
      return checksum;
    }
 
    unsigned n = 0;
  };
 
  auto table = std::array<std::uint_fast32_t, 256>{};
  std::generate(table.begin(), table.end(), byte_checksum{});
 
  return table;
}

template <typename T>
unsigned int crc32(T &value)
{
  // Generate lookup table only on first use then cache it - this is thread-safe.
  static auto const table = generate_crc_lookup_table();

  std::stringstream ss;
  ss << value;
  
  std::string val = ss.str();

  // Calculate the checksum - make sure to clip to 32 bits, for systems that don't
  // have a true (fast) 32-bit type.
  return std::uint_fast32_t{0xFFFFFFFFuL} &
    ~std::accumulate(val.begin(), val.end(),
      ~std::uint_fast32_t{0} & std::uint_fast32_t{0xFFFFFFFFuL},
        [](std::uint_fast32_t checksum, std::uint_fast8_t value) 
          { return table[(checksum ^ value) & 0xFFu] ^ (checksum >> 8); });

  return 0;

}
#endif
 