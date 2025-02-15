/***************************************************************************
    copyright            : (C) 2004 by Allan Sandfeld Jensen
    email                : kde@carewolf.org
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_MPCPROPERTIES_H
#define TAGLIB_MPCPROPERTIES_H

#include <taglib/taglib_export.h>
#include <taglib/audioproperties.h>

namespace TagLib {

  namespace MPC {

    class File;

    //! An implementation of audio property reading for MPC

    /*!
     * This reads the data from an MPC stream found in the AudioProperties
     * API.
     */

    class TAGLIB_EXPORT AudioProperties : public TagLib::AudioProperties
    {
    public:
      /*!
       * Creates an instance of MPC::AudioProperties with the data read directly
       * from a MPC::File.
       */
      AudioProperties(File *file, long long streamLength, ReadStyle style = Average);

      /*!
       * Destroys this MPC::Properties instance.
       */
      virtual ~AudioProperties();

      /*!
       * Returns the length of the file in seconds.  The length is rounded down to
       * the nearest whole second.
       *
       * \note This method is just an alias of lengthInSeconds().
       *
       * \deprecated
       */
      virtual int length() const;

      /*!
       * Returns the length of the file in seconds.  The length is rounded down to
       * the nearest whole second.
       *
       * \see lengthInMilliseconds()
       */
      virtual int lengthInSeconds() const;

      /*!
       * Returns the length of the file in milliseconds.
       *
       * \see lengthInSeconds()
       */
      virtual int lengthInMilliseconds() const;

      /*!
       * Returns the average bit rate of the file in kb/s.
       */
      virtual int bitrate() const;

      /*!
       * Returns the sample rate in Hz.
       */
      virtual int sampleRate() const;

      /*!
       * Returns the number of audio channels.
       */
      virtual int channels() const;

      /*!
       * Returns the version of the bitstream (SV4-SV8)
       */
      int mpcVersion() const;

      unsigned int totalFrames() const;
      unsigned int sampleFrames() const;

      /*!
      * Returns the track gain as an integer value,
      * to convert to dB: trackGain in dB = 64.82 - (trackGain / 256)
      */
      int trackGain() const;

      /*!
      * Returns the track peak as an integer value,
      * to convert to dB: trackPeak in dB = trackPeak / 256
      * to convert to floating [-1..1]: trackPeak = 10^(trackPeak / 256 / 20)/32768
      */
      int trackPeak() const;

      /*!
      * Returns the album gain as an integer value,
      * to convert to dB: albumGain in dB = 64.82 - (albumGain / 256)
      */
      int albumGain() const;

      /*!
      * Returns the album peak as an integer value,
      * to convert to dB: albumPeak in dB = albumPeak / 256
      * to convert to floating [-1..1]: albumPeak = 10^(albumPeak / 256 / 20)/32768
      */
      int albumPeak() const;

    private:
      void readSV7(const ByteVector &data, long long streamLength);
      void readSV8(File *file, long long streamLength);

      class PropertiesPrivate;
      PropertiesPrivate *d;
    };
  }
}

#endif
