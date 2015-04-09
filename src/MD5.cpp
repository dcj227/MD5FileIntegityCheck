#include "MD5.h"

//#include <boost/smart_ptr.hpp>
//#include <boost/make_shared.hpp>

//using namespace boost;

MD5::MD5() {
  Reset();
}

void MD5::Reset() {
  is_finished_ = false;
  /* reset number of bits */
  count_[0] = count_[1] = 0;
  /* Load magic initialization constant */
  state_[0] = 0x67452301;
  state_[1] = 0xefcdab89;
  state_[2] = 0x98badcfe;
  state_[3] = 0x10325476;
}

void MD5::Update(const BYTE * input, size_t length) {
  DWORD i, index, part_len;
  
  //
  is_finished_ = false; 
  //
  index = (DWORD)((count_[0] >> 3) & 0x3f);

  //
  if((count_[0] += ((DWORD)length << 3)) < ((DWORD)length << 3)) {
    count_[1]++;
  }
  count_[1] += ((DWORD)length >> 29);

  //
  part_len = 64 - index;

  //
  if (length >= part_len) {
    memcpy(&buffer_block_[index], input, part_len);
    Transform(buffer_block_);

    for (i = part_len; i + 63 < length; i += 64) {
      Transform(&input[i]);
    }
    index = 0;
  } else {
    i = 0;
  }

  //
  memcpy(&buffer_block_[index], &input[i], length - i);
}

void MD5::Transform(const BYTE block[64]) {
  
}
