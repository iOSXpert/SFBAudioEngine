/***************************************************************************
    copyright            : (C) 2006 by Lukáš Lalinský
    email                : lalinsky@gmail.com

    copyright            : (C) 2004 by Allan Sandfeld Jensen
    email                : kde@carewolf.org
                           (original MPC implementation)
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

#ifndef TAGLIB_WVPROPERTIES_H
#define TAGLIB_WVPROPERTIES_H

#include <taglib/taglib_export.h>
#include <taglib/audioproperties.h>

namespace TagLib {

  namespace WavPack {

    class File;

    static const unsigned int HeaderSize = 32;

    //! An implementation of audio property reading for WavPack

    /*!
     * This reads the data from an WavPack stream found in the AudioProperties
     * API.
     */

    class TAGLIB_EXPORT AudioProperties : public TagLib::AudioProperties
    {
    public:
      /*!
       * Creates an instance of WavPack::AudioProperties.
       */
      AudioProperties(File *file, long long streamLength, ReadStyle style = Average);

      /*!
       * Destroys this WavPack::AudioProperties instance.
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
       * Returns the sample rate in Hz. 0 means unknown or custom.
       */
      virtual int sampleRate() const;

      /*!
       * Returns the number of audio channels.
       */
      virtual int channels() const;

      /*!
       * Returns the number of bits per audio sample.
       */
      int bitsPerSample() const;

      /*!
       * Returns whether or not the file is lossless encoded.
       */
      bool isLossless() const;

      /*!
       * Returns the total number of audio samples in file.
       */
      unsigned int sampleFrames() const;

      /*!
       * Returns WavPack version.
       */
      int version() const;

    private:
      void read(File *file, long long streamLength);
      unsigned int seekFinalIndex(File *file, long long streamLength);

      class PropertiesPrivate;
      PropertiesPrivate *d;
    };
  }
}

#endif
