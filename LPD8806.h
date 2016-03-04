#include <stdlib.h>
#include <string.h>

#ifndef boolean
typedef bool boolean;
#endif
#ifndef byte
typedef char byte;
#endif
#ifndef uint8_t
typedef unsigned char uint8_t;
#endif
#ifndef uint16_t
typedef unsigned short uint16_t;
#endif
#ifndef uint32_t
typedef unsigned int uint32_t;
#endif

class LPD8806 {

 public:
  LPD8806(uint16_t n, uint8_t dpin, uint8_t cpin); // Configurable pins
  ~LPD8806();
  void
    begin(void),
    setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
    setPixelColor(uint16_t n, uint32_t c),
    clearPixelColors(),
    show(void),
    updatePins(uint8_t dpin, uint8_t cpin), // Change pins, configurable
    updateLength(uint16_t n);               // Change strip length
  uint16_t
    numPixels(void);
  uint32_t
    Color(byte, byte, byte) const,
    getPixelColor(uint16_t n) const;

 private:
  uint16_t numLEDs;    // Number of RGB LEDs in strip (each led needs 3 bytes)
  uint16_t largestChangedLed; // last LED changed after show().
  
  uint8_t
    *pixels,    // Holds LED color values (3 bytes each) + latch bytes
    clkpin, datapin;     // Clock & data pin numbers

  void startBitbang() const;
  void bitBangLatchSignal() const;
  boolean begun;       // If 'true', begin() method was previously invoked

  // not implemented
  LPD8806();
  LPD8806(const LPD8806& other);
  LPD8806& operator=(const LPD8806& other);
};
