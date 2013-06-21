/**
 * @author Edouard DUPIN
 * 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __ETK_XML_NODE_H__
#define __ETK_XML_NODE_H__

#include <etk/types.h>
#include <etk/UString.h>
#include <etk/math/Vector2D.h>

namespace exml
{
	class EXmlDocument;
	class EXmlAttribute;
	class EXmlComment;
	class EXmlDeclaration;
	class EXmlElement;
	class EXmlText;
	
	typedef enum {
		typeNode, //!< might be an error ...
		typeDocument, //!< all the file main access
		typeDeclaration, //!< <?xml ... ?>
		typeAttribute, //!< the <Element ATTRIBUTE="ATTRIBUTE_VALUE" />
		typeElement,  //!< the <XXX> ... </XXX>
		typeComment, //!< comment node : <!--   -->
		typeText, //!< <XXX> InsideText </XXX>
	} nodeType_te;
	
	class EXmlNode
	{
		public:
			EXmlNode(void) : m_pos(0,0) { };
			EXmlNode(const etk::UString& _value);
			virtual ~EXmlNode(void) { };
		protected:
			void AddIndent(etk::UString& _data, int32_t _indent) const;
		public:
			/**
			 * Parse the sub nodes and current nodes ...
			 */
			virtual bool Parse(const etk::UString& _data, int32_t& _pos, bool _caseSensitive, ivec2& _filePos) = 0;
			virtual bool Generate(etk::UString& _data, int32_t _indent) const { return true; };
		private:
			ivec2 m_pos; // position in the readed file
		public:
			const ivec2& Pos(void) { return m_pos; };
		protected:
			etk::UString m_value;
		public:
			virtual void SetValue(etk::UString _value) { m_value = _value; };
			virtual const etk::UString& GetValue(void) const { return m_value; };
		public:
			virtual nodeType_te GetType(void) const { return typeNode; };
		protected:
			void DrawElementParsed(const etk::UniChar& _val, const ivec2& _firstChar) const;
			bool CheckAvaillable(const etk::UniChar& _val, bool _firstChar) const;
			int32_t CountWhiteChar(const etk::UString& _data, int32_t _pos) const;
		public:
			virtual operator exml::EXmlDocument* () { return NULL; };
			virtual operator const exml::EXmlDocument* () const { return NULL; };
			virtual operator exml::EXmlAttribute* () { return NULL; };
			virtual operator const exml::EXmlAttribute* () const { return NULL; };
			virtual operator exml::EXmlComment* () { return NULL; };
			virtual operator const exml::EXmlComment* () const { return NULL; };
			virtual operator exml::EXmlDeclaration* () { return NULL; };
			virtual operator const exml::EXmlDeclaration* () const { return NULL; };
			virtual operator exml::EXmlElement* () { return NULL; };
			virtual operator const exml::EXmlElement* () const { return NULL; };
			virtual operator exml::EXmlText* () { return NULL; };
			virtual operator const exml::EXmlText* () const{ return NULL; };
			
			bool IsDocument(void) const { return GetType()==exml::typeDocument; };
			bool IsAttribute(void) const { return GetType()==exml::typeAttribute; };
			bool IsComment(void) const { return GetType()==exml::typeComment; };
			bool IsDeclaration(void) const { return GetType()==exml::typeDeclaration; };
			bool IsElement(void) const { return GetType()==exml::typeElement; };
			bool IsText(void) const { return GetType()==exml::typeText; };
	};
};

#endif

