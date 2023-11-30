#include <alsa/asoundlib.h>
#include <iostream>

int playSentence(const char* sentence) {
    // Open the PCM device in playback mode
    snd_pcm_t *pcm_handle;
    int rc = snd_pcm_open(&pcm_handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
    if (rc < 0) {
        std::cerr << "Error opening PCM device: " << snd_strerror(rc) << std::endl;
        return rc;
    }

    // Set the PCM format to signed 16-bit little-endian
    snd_pcm_set_params(pcm_handle, SND_PCM_FORMAT_S16_LE, SND_PCM_ACCESS_RW_INTERLEAVED, 1, 44100, 0, 500000);

    // Write the sentence to the PCM device
    rc = snd_pcm_writei(pcm_handle, sentence, strlen(sentence));
    if (rc == -EPIPE) {
        std::cerr << "Underrun occurred" << std::endl;
        snd_pcm_prepare(pcm_handle);
    } else if (rc < 0) {
        std::cerr << "Error writing to PCM device: " << snd_strerror(rc) << std::endl;
    }

    // Close the PCM device
    snd_pcm_close(pcm_handle);

    return 0;
}

int main() {
    const char* sentence = "Hello, this is a test sentence.";
    
    int result = playSentence(sentence);

    if (result == 0) {
        std::cout << "Sentence played successfully." << std::endl;
    } else {
        std::cerr << "Error playing sentence." << std::endl;
    }

    return 0;
}

