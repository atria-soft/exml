/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <exml/internal/AttributeList.hpp>
#include <exml/debug.hpp>

ememory::SharedPtr<exml::internal::Attribute> exml::internal::AttributeList::getAttr(int32_t _id) {
	if (    _id < 0
	     || size_t(_id) >= m_listAttribute.size()) {
		return null;
	}
	return m_listAttribute[_id];
}

ememory::SharedPtr<const exml::internal::Attribute> exml::internal::AttributeList::getAttr(int32_t _id) const {
	if (    _id < 0
	     || size_t(_id) >= m_listAttribute.size()) {
		return null;
	}
	return m_listAttribute[_id];
}

etk::Pair<etk::String, etk::String> exml::internal::AttributeList::getAttrPair(int32_t _id) const {
	ememory::SharedPtr<const exml::internal::Attribute> att = getAttr(_id);
	if (att == null) {
		return etk::makePair<etk::String, etk::String>("","");
	}
	return etk::makePair(att->getName(),att->getValue());
}


void exml::internal::AttributeList::appendAttribute(const ememory::SharedPtr<exml::internal::Attribute>& _attr) {
	if (_attr == null) {
		EXML_ERROR("Try to set an empty node");
		return;
	}
	for (size_t iii=0; iii<m_listAttribute.size(); iii++) {
		if (m_listAttribute[iii] == _attr) {
			EXML_ERROR("Try to add a node that is already added befor !!!");
			return;
		}
	}
	m_listAttribute.pushBack(_attr);
}

const etk::String& exml::internal::AttributeList::getAttribute(const etk::String& _name) const {
	static const etk::String errorReturn("");
	if (_name.size() == 0) {
		return errorReturn;
	}
	for (size_t iii=0; iii<m_listAttribute.size(); iii++) {
		if(    m_listAttribute[iii] != null
		    && m_listAttribute[iii]->getName() == _name) {
			return m_listAttribute[iii]->getValue();
		}
	}
	return errorReturn;
}


bool exml::internal::AttributeList::existAttribute(const etk::String& _name) const {
	if (_name.size() == 0) {
		return false;
	}
	for (size_t iii=0; iii<m_listAttribute.size(); ++iii) {
		if(    m_listAttribute[iii] != null
		    && m_listAttribute[iii]->getName() == _name) {
			return true;
		}
	}
	return false;
}

bool exml::internal::AttributeList::removeAttribute(const etk::String& _name) {
	if (_name.size() == 0) {
		return false;
	}
	auto it = m_listAttribute.begin();
	while (it != m_listAttribute.end()) {
		if (*it == null) {
			it = m_listAttribute.erase(it);
			continue;
		}
		if((*it)->getName() == _name) {
			it = m_listAttribute.erase(it);
			return true;
		}
		it++;
	}
	return false;
}

void exml::internal::AttributeList::setAttribute(const etk::String& _name, const etk::String& _value) {
	// check if attribute already det :
	for (size_t iii=0; iii<m_listAttribute.size(); ++iii) {
		if(    m_listAttribute[iii] != null
		    && m_listAttribute[iii]->getName() == _name) {
			// update the value :
			m_listAttribute[iii]->setValue(_value);
			return;
		}
	}
	ememory::SharedPtr<exml::internal::Attribute> attr = exml::internal::Attribute::create(_name, _value);
	if (attr == null) {
		EXML_ERROR("memory allocation error...");
	}
	m_listAttribute.pushBack(attr);
}

bool exml::internal::AttributeList::iGenerate(etk::String& _data, int32_t _indent) const {
	for (size_t iii=0; iii<m_listAttribute.size(); iii++) {
		if (m_listAttribute[iii] != null) {
			m_listAttribute[iii]->iGenerate(_data, _indent);
		}
	}
	return true;
}

void exml::internal::AttributeList::clear() {
	exml::internal::Node::clear();
	m_listAttribute.clear();
}


