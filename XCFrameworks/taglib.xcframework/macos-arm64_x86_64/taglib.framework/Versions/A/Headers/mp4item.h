/**************************************************************************
    copyright            : (C) 2007 by Lukáš Lalinský
    email                : lalinsky@gmail.com
 **************************************************************************/

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

#ifndef TAGLIB_MP4ITEM_H
#define TAGLIB_MP4ITEM_H

#include <taglib/tstringlist.h>
#include <taglib/mp4coverart.h>
#include <taglib/taglib_export.h>

namespace TagLib {

  namespace MP4 {

    class TAGLIB_EXPORT Item
    {
    public:
      struct IntPair {
        int first, second;
      };

      enum ItemType {
        TypeUndefined = 0,
        TypeBool,
        TypeInt,
        TypeIntPair,
        TypeByte,
        TypeUInt,
        TypeLongLong,
        TypeStringList,
        TypeByteVectorList,
        TypeCoverArtList,
      };

      Item();
      Item(const Item &item);

      /*!
       * Copies the contents of \a item into this Item.
       */
      Item &operator=(const Item &item);

      /*!
       * Exchanges the content of the Item by the content of \a item.
       */
      void swap(Item &item);

      ~Item();

      Item(int value);
      Item(unsigned char value);
      Item(unsigned int value);
      Item(long long value);
      Item(bool value);
      Item(int first, int second);
      Item(const StringList &value);
      Item(const ByteVectorList &value);
      Item(const CoverArtList &value);

      void setAtomDataType(AtomDataType type);
      AtomDataType atomDataType() const;

      int toInt() const;
      unsigned char toByte() const;
      unsigned int toUInt() const;
      long long toLongLong() const;
      bool toBool() const;
      IntPair toIntPair() const;
      StringList toStringList() const;
      ByteVectorList toByteVectorList() const;
      CoverArtList toCoverArtList() const;

      ItemType type() const;

      bool isValid() const;

      String toString() const;

    private:
      class ItemPrivate;
      ItemPrivate *d;
    };

  }

}

#endif
