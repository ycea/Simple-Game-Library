#include "Audio.h"
extern "C"
{

#include <SDL2/SDL.h>
}

void Audio::audio_callback(void *user_data, uint8_t *stream, int len)
{
    if(audio_len == 0)
    {
        return;
    }
    len = (len > audio_len ? audio_len : len);

    SDL_MixAudio(stream, audio_buffer, len, SDL_MIX_MAXVOLUME);
    audio_buffer += len;
    audio_len -= len;
}

int Audio::make_sound(const char* file)
{

    uint8_t *wav_buffer;
    uint32_t wav_len;
    SDL_AudioSpec wav_spec;

    if(SDL_LoadWAV(file, &wav_spec, &wav_buffer, &wav_len) == NULL)
    {
        return 1;
    }
    else
    {
        wav_spec.userdata = NULL;
        audio_buffer = wav_buffer;
        audio_len = wav_len;
        if(SDL_OpenAudio(&wav_spec, NULL) < 0)
        {
            return 1;
        }
        SDL_PauseAudio(0);
        while(audio_len > 0)
        {
            SDL_Delay(100);
        }
        SDL_CloseAudio();
        SDL_FreeWAV(wav_buffer);
    }
    return 0;
}
