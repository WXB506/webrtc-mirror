/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_API_AUDIO_CODECS_L16_AUDIO_DECODER_L16_H_
#define WEBRTC_API_AUDIO_CODECS_L16_AUDIO_DECODER_L16_H_

#include <memory>
#include <vector>

#include "webrtc/api/audio_codecs/audio_decoder.h"
#include "webrtc/api/audio_codecs/audio_format.h"
#include "webrtc/api/optional.h"

namespace webrtc {

// L16 decoder API for use as a template parameter to
// CreateAudioDecoderFactory<...>().
//
// NOTE: This struct is still under development and may change without notice.
struct AudioDecoderL16 {
  struct Config {
    bool IsOk() const {
      return (sample_rate_hz == 8000 || sample_rate_hz == 16000 ||
              sample_rate_hz == 32000 || sample_rate_hz == 48000) &&
             num_channels >= 1;
    }
    int sample_rate_hz = 8000;
    int num_channels = 1;
  };
  static rtc::Optional<Config> SdpToConfig(const SdpAudioFormat& audio_format);
  static void AppendSupportedDecoders(std::vector<AudioCodecSpec>* specs);
  static std::unique_ptr<AudioDecoder> MakeAudioDecoder(const Config& config);
};

}  // namespace webrtc

#endif  // WEBRTC_API_AUDIO_CODECS_L16_AUDIO_DECODER_L16_H_
