/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <exml/internal/Node.hpp>
#include <etk/Vector.hpp>

namespace exml {
	namespace internal {
		/**
		 * @brief Single attribute element
		 */
		class Attribute : public exml::internal::Node {
			protected:
				/**
				 * @brief Constructor
				 * @param[in] _name Name of the attribute.
				 * @param[in] _value Value of the attribute.
				 */
				Attribute(const etk::String& _name="", const etk::String& _value="");
			public:
				/**
				 * @brief defined factory
				 * @param[in] _name Name of the attribute
				 * @param[in] _value Value of the attribute
				 * @return Shared pointer on the Attribute element
				 */
				static ememory::SharedPtr<Attribute> create(const etk::String& _name="", const etk::String& _value="");
			protected:
				etk::String m_name; //!< Name of the attribute
			public:
				/**
				 * @brief set the name of the attribute
				 * @param[in] _name New name of the attribute
				 */
				virtual void setName(const etk::String& _name) {
					m_name = _name;
				};
				/**
				 * @brief get the current name of the Attribute
				 * @return String of the attribute
				 */
				virtual const etk::String& getName() const {
					return m_name;
				};
			public:
				enum nodeType getType() const override {
					return exml::nodeType::attribute;
				};
				bool iParse(const etk::String& _data, int32_t& _pos, bool _caseSensitive, exml::FilePos& _filePos, exml::internal::Document& _doc) override;
				bool iGenerate(etk::String& _data, int32_t _indent) const override;
				ememory::SharedPtr<exml::internal::Attribute> toAttribute() override {
					return ememory::staticPointerCast<exml::internal::Attribute>(sharedFromThis());
				};
				const ememory::SharedPtr<exml::internal::Attribute> toAttribute() const override {
					return ememory::staticPointerCast<exml::internal::Attribute>(sharedFromThis());
				};
				void clear() override;
		};
	}
}

