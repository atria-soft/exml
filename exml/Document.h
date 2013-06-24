/**
 * @author Edouard DUPIN
 * 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __ETK_XML_DOCUMENT_H__
#define __ETK_XML_DOCUMENT_H__

#include <exml/Element.h>
#include <etk/unicode.h>
#include <etk/Vector.h>

namespace exml
{
	class Document : public exml::Element
	{
		public:
			Document(void);
			virtual ~Document(void) { };
			virtual nodeType_te GetType(void) const { return typeDocument; };
		private:
			unicode::charset_te m_charset;
		public:
			virtual void SetCharset(unicode::charset_te _charset) { m_charset = _charset; };
			virtual unicode::charset_te GetCharset(void) const { return m_charset; };
		private:
			bool m_caseSensitive;
		public:
			virtual void SetCaseSensitive(bool _val) { m_caseSensitive = _val; };
			virtual bool GetCaseSensitive(void) const { return m_caseSensitive; };
		public:
			/**
			 * @brief Parse a string that contain an XML
			 * @param[in] _data Data to parse
			 * @return false : An error occured
			 * @return true : Parsing is OK
			 */
			bool Parse(const etk::UString& _data);
			/**
			 * @brief Generate a string that contain the created XML
			 * @param[out] _data Data where the xml is stored
			 * @return false : An error occured
			 * @return true : Parsing is OK
			 */
			bool Generate(etk::UString& _data);
			/**
			 * @brief Load the file that might contain the xml
			 * @param[in] _file Filename of the xml (compatible with etk FSNode naming)
			 * @return false : An error occured
			 * @return true : Parsing is OK
			 */
			bool Load(const etk::UString& _file);
			/**
			 * @brief Store the Xml in the file
			 * @param[in] _file Filename of the xml (compatible with etk FSNode naming)
			 * @return false : An error occured
			 * @return true : Parsing is OK
			 */
			bool Store(const etk::UString& _file);
			
			void Display(void);
			bool Parse(const etk::UString& _data, int32_t& _pos, bool _caseSensitive, ivec2& _filePos);
			bool Generate(etk::UString& _data, int32_t _indent) const;
			virtual operator exml::Document* () { return this; };
			virtual operator const exml::Document* () const { return this; };
	};
};


#endif

