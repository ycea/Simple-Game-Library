#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED
#include <cstdint>

class Audio
{
private:
    uint8_t *audio_buffer;
    uint32_t audio_len;
    void audio_callback(void *user_data, uint8_t *stream, int len);
public:
    int make_sound(const char* file);
};

#endif // AUDIO_H_INCLUDED
