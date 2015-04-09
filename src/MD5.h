#ifndef MD5_H
#define MD5_h

#include <sys/types.h>

#include <string>
#include <fstream>

typedef unsigned char BYTE;
typedef unsigned int  DWORD;

using std::string;
using std::ifstream;

class MD5 {
 public:
  MD5();
  MD5(const string &str);
  MD5(ifstream *in);
  // 
  void Update(const void * input, size_t length);
  //
  void Update(const string &str);
  void Update(ifstream &in);
  const BYTE * GetDigest();
  string Tostring();
  void Reset();

 private:
  //
  void Update(const BYTE * input, size_t length);
  void Stop();
  void Transform(const BYTE block[64]);
  //
  void Encode(const DWORD * input, BYTE * output, size_t length);
  //
  void Decode(const BYTE * input, DWORD * output, size_t length);
  //
  std::string BytesToHexString(const BYTE * input, size_t length);

  /* class uncopyable */
  MD5(const MD5&);
  MD5& operator=(const MD5&);

 private:
  DWORD state_[4];         // the four initial vectors
  DWORD count_[2];         // for count, count[0]:low bits, count[1]:high bits
  BYTE buffer_block_[64];  //
  BYTE digest_[16];        //
  bool is_finished_;       //

  static const BYTE padding[64];
  static const char hex[16];
  static const size_t BUFFER_SIZE = 1024;
};

#endif  /* MD5_H */
