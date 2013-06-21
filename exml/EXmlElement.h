/**
 * @author Edouard DUPIN
 * 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __ETK_XML_ELEMENT_H__
#define __ETK_XML_ELEMENT_H__

#include <exml/EXmlNode.h>
#include <etk/Vector.h>
#include <exml/EXmlAttribute.h>

namespace exml
{
	class EXmlElement : public EXmlNode
	{
		public:
			EXmlElement(void) { };
			EXmlElement(const etk::UString& _value) : exml::EXmlNode(_value) { };
			virtual ~EXmlElement(void) { };
			virtual nodeType_te GetType(void) { return typeElement; };
		protected:
			etk::Vector<exml::EXmlNode*> m_listSub;
		public:
			int32_t SizeSub(void) const { return m_listSub.Size(); };
			EXmlNode* GetSub(int32_t _id);
			void AppendSub(EXmlNode* _node);
		protected:
			etk::Vector<exml::EXmlAttribute*> m_listAttribute;
		public:
			int32_t SizeAttribute(void) const { return m_listSub.Size(); };
			EXmlAttribute* GetAttribute(int32_t _id);
			void AppendAttribute(EXmlAttribute* _node);
		public:
			virtual bool Parse(const etk::UString& _data, int32_t& _pos, bool _caseSensitive, ivec2& _filePos);
			virtual bool Generate(etk::UString& _data, int32_t _indent);
		protected:
			bool SubParse(const etk::UString& _data, int32_t& _pos, bool _caseSensitive, ivec2& _filePos, bool _mainNode=false);
			
			const etk::UString& GetAttribute(const etk::UString& _name);
	};
};


#endif

