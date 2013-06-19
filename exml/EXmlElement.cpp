/**
 * @author Edouard DUPIN
 * 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#include <exml/EXmlElement.h>


EXmlNode* exml::EXmlElement::GetSub(int32_t _id)
{
	if (_id <0 || _id>m_listSub.Size()) {
		return NULL;
	}
	return m_listSub[_id];
}

void exml::EXmlElement::AppendSub(EXmlNode* _node)
{
	if (_node == NULL) {
		EXML_ERROR("Try to set an empty node");
		return;
	}
	for (int32_t iii=0; iii<m_listSub.Size(); iii++) {
		if (m_listSub[iii] == _node) {
			EXML_ERROR("Try to add a node that is already added befor !!!");
			return;
		}
	}
	m_listSub.PushBack(_node);
}

EXmlAttribute* exml::EXmlElement::GetAttribute(int32_t _id)
{
	if (_id <0 || _id>m_listAttribute.Size()) {
		return NULL;
	}
	return m_listAttribute[_id];
}
void exml::EXmlElement::AppendAttribute(EXmlAttribute* _node)
{
	if (_node == NULL) {
		EXML_ERROR("Try to set an empty node");
		return;
	}
	for (int32_t iii=0; iii<m_listAttribute.Size(); iii++) {
		if (m_listAttribute[iii] == _node) {
			EXML_ERROR("Try to add a node that is already added befor !!!");
			return;
		}
	}
	m_listAttribute.PushBack(_node);
}

int32_t exml::EXmlElement::Parse(const etk::UString& _data, int32_t _pos, bool _caseSensitive, ivec2& _filePos)
{
	for (int32_t iii=_pos; iii<_data.Size(); iii++) {
		if (_data[iii] == "<") {
			if (iii+1>=_data.Size()) {
				// TODO : an error occured ...
				return;
			}
			// find the end of the balise : 
			int32_t endPos = iii;
			for (int32_t jjj=iii+1; jjj<_data.Size(); jjj++) {
				if(_data[jjj] == ">") {
					endPos = jjj;
					break;
				}
			}
			if (endPos == iii) {
				// TODO : an error occured ...
				return;
			}
			int32_t sizeElement = endPos-iii;
			if(    sizeElement>2
			    && _data[iii+1] == '?'
			    && _data[endPos-1] == '?') {
				// find declaration
				
				// TODO : ...
				
				iii = endPos
				continue;
			}
			if(    sizeElement>5
			    && _data[iii+1] == '!'
			    && _data[iii+2] == '-'
			    && _data[iii+3] == '-'
			    && _data[endPos-2] == '-'
			    && _data[endPos-1] == '-') {
				// find comment
				// TODO : Change the end parsing ...
				
				
				// TODO : ...
				
				iii = endPos
				continue;
			}
			// find a normal node ...
			// TODO : ...
			for (int32_t jjj=iii+1; jjj<_data.Size(); jjj++) {
				if(_data[jjj] == ">") {
					// we find the end ...
					iii = jjj;
					break;
				}
			}
		} else {
			// might to be data text ...
		}
	}
}


#endif




