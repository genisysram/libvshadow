/*
 * Codepage definitions for libvshadow
 *
 * Copyright (C) 2011-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBVSHADOW_CODEPAGE_H )
#define _LIBVSHADOW_CODEPAGE_H

#include <libvshadow/types.h>

#if defined( __cplusplus )
extern "C" {
#endif

/* The codepage definitions
 */
enum LIBVSHADOW_CODEPAGES
{
	LIBVSHADOW_CODEPAGE_ASCII			= 20127,

	LIBVSHADOW_CODEPAGE_ISO_8859_1			= 28591,
	LIBVSHADOW_CODEPAGE_ISO_8859_2			= 28592,
	LIBVSHADOW_CODEPAGE_ISO_8859_3			= 28593,
	LIBVSHADOW_CODEPAGE_ISO_8859_4			= 28594,
	LIBVSHADOW_CODEPAGE_ISO_8859_5			= 28595,
	LIBVSHADOW_CODEPAGE_ISO_8859_6			= 28596,
	LIBVSHADOW_CODEPAGE_ISO_8859_7			= 28597,
	LIBVSHADOW_CODEPAGE_ISO_8859_8			= 28598,
	LIBVSHADOW_CODEPAGE_ISO_8859_9			= 28599,
	LIBVSHADOW_CODEPAGE_ISO_8859_10			= 28600,
	LIBVSHADOW_CODEPAGE_ISO_8859_11			= 28601,
	LIBVSHADOW_CODEPAGE_ISO_8859_13			= 28603,
	LIBVSHADOW_CODEPAGE_ISO_8859_14			= 28604,
	LIBVSHADOW_CODEPAGE_ISO_8859_15			= 28605,
	LIBVSHADOW_CODEPAGE_ISO_8859_16			= 28606,

	LIBVSHADOW_CODEPAGE_KOI8_R			= 20866,
	LIBVSHADOW_CODEPAGE_KOI8_U			= 21866,

	LIBVSHADOW_CODEPAGE_WINDOWS_874			= 874,
	LIBVSHADOW_CODEPAGE_WINDOWS_932			= 932,
	LIBVSHADOW_CODEPAGE_WINDOWS_936			= 936,
	LIBVSHADOW_CODEPAGE_WINDOWS_949			= 949,
	LIBVSHADOW_CODEPAGE_WINDOWS_950			= 950,
	LIBVSHADOW_CODEPAGE_WINDOWS_1250		= 1250,
	LIBVSHADOW_CODEPAGE_WINDOWS_1251		= 1251,
	LIBVSHADOW_CODEPAGE_WINDOWS_1252		= 1252,
	LIBVSHADOW_CODEPAGE_WINDOWS_1253		= 1253,
	LIBVSHADOW_CODEPAGE_WINDOWS_1254		= 1254,
	LIBVSHADOW_CODEPAGE_WINDOWS_1255		= 1255,
	LIBVSHADOW_CODEPAGE_WINDOWS_1256		= 1256,
	LIBVSHADOW_CODEPAGE_WINDOWS_1257		= 1257,
	LIBVSHADOW_CODEPAGE_WINDOWS_1258		= 1258
};

#define LIBVSHADOW_CODEPAGE_US_ASCII			LIBVSHADOW_CODEPAGE_ASCII

#define LIBVSHADOW_CODEPAGE_ISO_WESTERN_EUROPEAN	LIBVSHADOW_CODEPAGE_ISO_8859_1
#define LIBVSHADOW_CODEPAGE_ISO_CENTRAL_EUROPEAN	LIBVSHADOW_CODEPAGE_ISO_8859_2
#define LIBVSHADOW_CODEPAGE_ISO_SOUTH_EUROPEAN		LIBVSHADOW_CODEPAGE_ISO_8859_3
#define LIBVSHADOW_CODEPAGE_ISO_NORTH_EUROPEAN		LIBVSHADOW_CODEPAGE_ISO_8859_4
#define LIBVSHADOW_CODEPAGE_ISO_CYRILLIC		LIBVSHADOW_CODEPAGE_ISO_8859_5
#define LIBVSHADOW_CODEPAGE_ISO_ARABIC			LIBVSHADOW_CODEPAGE_ISO_8859_6
#define LIBVSHADOW_CODEPAGE_ISO_GREEK			LIBVSHADOW_CODEPAGE_ISO_8859_7
#define LIBVSHADOW_CODEPAGE_ISO_HEBREW			LIBVSHADOW_CODEPAGE_ISO_8859_8
#define LIBVSHADOW_CODEPAGE_ISO_TURKISH			LIBVSHADOW_CODEPAGE_ISO_8859_9
#define LIBVSHADOW_CODEPAGE_ISO_NORDIC			LIBVSHADOW_CODEPAGE_ISO_8859_10
#define LIBVSHADOW_CODEPAGE_ISO_THAI			LIBVSHADOW_CODEPAGE_ISO_8859_11
#define LIBVSHADOW_CODEPAGE_ISO_BALTIC			LIBVSHADOW_CODEPAGE_ISO_8859_13
#define LIBVSHADOW_CODEPAGE_ISO_CELTIC			LIBVSHADOW_CODEPAGE_ISO_8859_14

#define LIBVSHADOW_CODEPAGE_ISO_LATIN_1			LIBVSHADOW_CODEPAGE_ISO_8859_1
#define LIBVSHADOW_CODEPAGE_ISO_LATIN_2			LIBVSHADOW_CODEPAGE_ISO_8859_2
#define LIBVSHADOW_CODEPAGE_ISO_LATIN_3			LIBVSHADOW_CODEPAGE_ISO_8859_3
#define LIBVSHADOW_CODEPAGE_ISO_LATIN_4			LIBVSHADOW_CODEPAGE_ISO_8859_4
#define LIBVSHADOW_CODEPAGE_ISO_LATIN_5			LIBVSHADOW_CODEPAGE_ISO_8859_9
#define LIBVSHADOW_CODEPAGE_ISO_LATIN_6			LIBVSHADOW_CODEPAGE_ISO_8859_10
#define LIBVSHADOW_CODEPAGE_ISO_LATIN_7			LIBVSHADOW_CODEPAGE_ISO_8859_13
#define LIBVSHADOW_CODEPAGE_ISO_LATIN_8			LIBVSHADOW_CODEPAGE_ISO_8859_14
#define LIBVSHADOW_CODEPAGE_ISO_LATIN_9			LIBVSHADOW_CODEPAGE_ISO_8859_15
#define LIBVSHADOW_CODEPAGE_ISO_LATIN_10		LIBVSHADOW_CODEPAGE_ISO_8859_16

#define LIBVSHADOW_CODEPAGE_KOI8_RUSSIAN		LIBVSHADOW_CODEPAGE_KOI8_R
#define LIBVSHADOW_CODEPAGE_KOI8_UKRAINIAN		LIBVSHADOW_CODEPAGE_KOI8_U

#define LIBVSHADOW_CODEPAGE_WINDOWS_THAI		LIBVSHADOW_CODEPAGE_WINDOWS_874
#define LIBVSHADOW_CODEPAGE_WINDOWS_JAPANESE		LIBVSHADOW_CODEPAGE_WINDOWS_932
#define LIBVSHADOW_CODEPAGE_WINDOWS_CHINESE_SIMPLIFIED	LIBVSHADOW_CODEPAGE_WINDOWS_936
#define LIBVSHADOW_CODEPAGE_WINDOWS_KOREAN		LIBVSHADOW_CODEPAGE_WINDOWS_949
#define LIBVSHADOW_CODEPAGE_WINDOWS_CHINESE_TRADITIONAL	LIBVSHADOW_CODEPAGE_WINDOWS_950
#define LIBVSHADOW_CODEPAGE_WINDOWS_CENTRAL_EUROPEAN	LIBVSHADOW_CODEPAGE_WINDOWS_1250
#define LIBVSHADOW_CODEPAGE_WINDOWS_CYRILLIC		LIBVSHADOW_CODEPAGE_WINDOWS_1251
#define LIBVSHADOW_CODEPAGE_WINDOWS_WESTERN_EUROPEAN	LIBVSHADOW_CODEPAGE_WINDOWS_1252
#define LIBVSHADOW_CODEPAGE_WINDOWS_GREEK		LIBVSHADOW_CODEPAGE_WINDOWS_1253
#define LIBVSHADOW_CODEPAGE_WINDOWS_TURKISH		LIBVSHADOW_CODEPAGE_WINDOWS_1254
#define LIBVSHADOW_CODEPAGE_WINDOWS_HEBREW		LIBVSHADOW_CODEPAGE_WINDOWS_1255
#define LIBVSHADOW_CODEPAGE_WINDOWS_ARABIC		LIBVSHADOW_CODEPAGE_WINDOWS_1256
#define LIBVSHADOW_CODEPAGE_WINDOWS_BALTIC		LIBVSHADOW_CODEPAGE_WINDOWS_1257
#define LIBVSHADOW_CODEPAGE_WINDOWS_VIETNAMESE		LIBVSHADOW_CODEPAGE_WINDOWS_1258

#if defined( __cplusplus )
}
#endif

#endif

