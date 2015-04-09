#include <string>

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

 private:
  DWORD state[4];         // the four initial vectors
  DWORD count[2];         // for count, count[0]:low bits, count[1]:high bits
  BYTE buffer_block[64];  //
  BYTE digest[16];        //
  bool is_finished;       //

  static const BYTE padding[64];
  static const char hex[16];
};
