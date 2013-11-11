/**
 * @author Edouard DUPIN
 * 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#include <exml/Comment.h>
#include <exml/debug.h>
#include <exml/Document.h>

#undef __class__
#define __class__	"Comment"

bool exml::Comment::iParse(const std::u32string& _data, int32_t& _pos, bool _caseSensitive, exml::filePos& _filePos, exml::Document& _doc) {
	EXML_VERBOSE("start parse : 'comment'");
	m_pos = _filePos;
	exml::filePos tmpPos;
	int32_t white = countWhiteChar(_data, _pos, tmpPos);
	_filePos += tmpPos;
	// search end of the comment :
	for (int32_t iii=_pos+white; iii+2<_data.size(); iii++) {
		#ifdef ENABLE_DISPLAY_PARSED_ELEMENT
		 drawElementParsed(_data[iii], _filePos);
		#endif
		if (_filePos.check(_data[iii]) == true) {
			continue;
		}
		if(    _data[iii] == '-'
		    && _data[iii+1] == '-'
		    && _data[iii+2] == '>') {
			_filePos += 2;
			// search whitespace :
			int32_t newEnd=iii;
			for( int32_t jjj=iii-1; jjj>_pos; jjj--) {
				if(true == etk::isWhiteChar(_data[jjj])) {
					newEnd = jjj;
				} else {
					break;
				}
			}
			// find end of value:
			m_value = std::u32string(_data, _pos+white, newEnd);
			EXML_VERBOSE(" find comment '" << m_value << "'");
			_pos = iii+2;
			return true;
		}
	}
	_pos = _data.size();
	CREATE_ERROR(_doc, _data, _pos, _filePos, U"comment got end of file without finding end node");
	return false;
}

bool exml::Comment::iGenerate(std::u32string& _data, int32_t _indent) const {
	addIndent(_data, _indent);
	_data += U"<!--";
	_data += m_value;
	_data += U"-->\n";
	return true;
}