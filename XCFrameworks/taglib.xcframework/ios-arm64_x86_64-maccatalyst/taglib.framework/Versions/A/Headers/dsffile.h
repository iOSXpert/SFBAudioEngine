/***************************************************************************
    copyright            : (C) 2013 - 2018 by Stephen F. Booth
    email                : me@sbooth.org
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

#ifndef TAGLIB_DSFFILE_H
#define TAGLIB_DSFFILE_H

#include <taglib/tfile.h>
#include <taglib/id3v2tag.h>
#include <taglib/dsfproperties.h>

namespace TagLib {

  //! An implementation of DSF metadata

  /*!
   * This is implementation of DSF metadata.
   *
   * This supports an ID3v2 tag as well as properties from the file.
   */

  namespace DSF {

    //! An implementation of TagLib::File with DSF specific methods

    /*!
     * This implements and provides an interface for DSF files to the
     * TagLib::Tag and TagLib::AudioProperties interfaces by way of implementing
     * the abstract TagLib::File API as well as providing some additional
     * information specific to DSF files.
     */

    class TAGLIB_EXPORT File : public TagLib::File
    {
    public:
      /*!
       * Contructs an DSF file from \a file.  If \a readProperties is true the
       * file's audio properties will also be read using \a propertiesStyle.  If
       * false, \a propertiesStyle is ignored.
       */
      File(FileName file, bool readProperties = true,
           AudioProperties::ReadStyle propertiesStyle = AudioProperties::Average);

      /*!
       * Contructs an DSF file from \a file.  If \a readProperties is true the
       * file's audio properties will also be read using \a propertiesStyle.  If
       * false, \a propertiesStyle is ignored.
       */
      File(IOStream *stream, bool readProperties = true,
           AudioProperties::ReadStyle propertiesStyle = AudioProperties::Average);

      /*!
       * Destroys this instance of the File.
       */
      virtual ~File();

      /*!
       * Returns the Tag for this file.
       */
      virtual ID3v2::Tag *tag() const;

      /*!
       * Returns the DSF::AudioProperties for this file.  If no audio properties
       * were read then this will return a null pointer.
       */
      virtual AudioProperties *audioProperties() const;

       /*!
        * Implements the unified property interface -- export function.
        * This method forwards to ID3v2::Tag::properties().
        */
      virtual PropertyMap properties() const;

       /*!
        * Implements the unified property interface -- import function.
        * This method forwards to ID3v2::Tag::setProperties().
        */
       virtual PropertyMap setProperties(const PropertyMap &);

      /*!
       * Saves the file.
       */
      virtual bool save();

      /*!
       * Returns whether or not the given \a stream can be opened as a DSF
       * file.
       *
       * \note This method is designed to do a quick check.  The result may
       * not necessarily be correct.
       */
      static bool isSupported(IOStream *stream);

    private:
      File(const File &);
      File &operator=(const File &);

      void read(bool readProperties, AudioProperties::ReadStyle propertiesStyle);

      class FilePrivate;
      FilePrivate *d;
    };
  }
}

#endif
