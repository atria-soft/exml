/**
 * @author Edouard DUPIN
 * 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#include <exml/Comment.h>
#include <exml/debug.h>

#undef __class__
#define __class__	"Comment"

bool exml::Comment::Parse(const etk::UString& _data, int32_t& _pos, bool _caseSensitive, ivec2& _filePos)
{
	EXML_VERBOSE("start parse : 'comment'");
	m_pos = _filePos;
	// search end of the comment :
	for (int32_t iii=_pos; iii+2<_data.Size(); iii++) {
		_filePos += ivec2(1,0);
		#ifdef ENABLE_DISPLAY_PARSED_ELEMENT
			DrawElementParsed(_data[iii], _filePos);
		#endif
		if (_data[iii] == '\n') {
			_filePos.setValue(1, _filePos.y()+1);
			continue;
		}
		if(    _data[iii] == '-'
		    && _data[iii+1] == '-'
		    && _data[iii+2] == '>') {
			// find end of value:
			m_value = _data.Extract(_pos, iii-1);
			EXML_VERBOSE(" find comment '" << m_value << "'");
			_pos = iii+2;
			return true;
		}
	}
	_pos = _data.Size();
	EXML_ERROR("comment got end of file without finding end node");
	return false;
}

bool exml::Comment::Generate(etk::UString& _data, int32_t _indent) const
{
	AddIndent(_data, _indent);
	_data += "<!--";
	_data += m_value;
	_data += "-->\n";
	return true;
}