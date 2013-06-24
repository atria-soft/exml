/**
 * @author Edouard DUPIN
 * 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __ETK_XML_ATTRIBUTE_H__
#define __ETK_XML_ATTRIBUTE_H__

#include <exml/Node.h>
#include <etk/Vector.h>

namespace exml
{
	class Attribute : public Node
	{
		public:
			Attribute(void) { };
			Attribute(const etk::UString& _name, const etk::UString& _value);
			virtual ~Attribute(void) { };
			virtual nodeType_te GetType(void) const { return exml::typeAttribute; };
			virtual bool Parse(const etk::UString& _data, int32_t& _pos, bool _caseSensitive, ivec2& _filePos);
			virtual bool Generate(etk::UString& _data, int32_t _indent) const;
		protected:
			etk::UString m_name;
		public:
			virtual void SetName(etk::UString _name) { m_name = _name; };
			virtual const etk::UString& GetName(void) const { return m_name; };
			virtual operator exml::Attribute* () { return this; };
			virtual operator const exml::Attribute* () const { return this; };
	};
};


#endif
