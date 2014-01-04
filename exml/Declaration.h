/**
 * @author Edouard DUPIN
 * 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __ETK_XML_DECLARATION_H__
#define __ETK_XML_DECLARATION_H__

#include <exml/AttributeList.h>

namespace exml {
	class Declaration : public exml::AttributeList {
		public:
			/**
			 * @brief Constructor
			 */
			Declaration(void) { };
			/**
			 * @brief Constructor
			 * @param[in] _name name of the declaration (xml, xml:xxxx ...)
			 */
			Declaration(const std::string& _name) :
			  exml::AttributeList(_name) {
				
			};
			/**
			 * @brief Destructor
			 */
			virtual ~Declaration(void) { };
		public: // herited function:
			virtual enum nodeType getType(void) const {
				return typeAttribute;
			};
			virtual bool iGenerate(std::string& _data, int32_t _indent) const;
			virtual bool iParse(const std::string& _data, int32_t& _pos, bool _caseSensitive, exml::filePos& _filePos, exml::Document& _doc);
			virtual exml::Declaration* toDeclaration(void) {
				return this;
			};
			virtual const exml::Declaration* toDeclaration(void) const {
				return this;
			};
	};
	class DeclarationXML : public exml::Declaration {
		public:
			/**
			 * @brief Constructor for the generic declaration : <?xml version="" format="UTF-8"?>
			 * @param[in] _version Xml version.
			 * @param[in] _format charset of the XML
			 * @param[in] _standalone this document is standalone
			 */
			DeclarationXML(const std::string& _version, const std::string& _format = "UTF-8", bool _standalone = true);
			/**
			 * @brief Destructor
			 */
			virtual ~DeclarationXML(void) { };
	};
};


#endif
