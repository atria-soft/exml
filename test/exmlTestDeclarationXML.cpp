/** @file
 * @author Edouard DUPIN
 * @copyright 2014, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <etest/etest.hpp>
#include <exml/exml.hpp>
#include <exml/Declaration.hpp>

TEST(TestDeclarationXML, create) {
	exml::DeclarationXML myDeclarationXML("1.0", "UTF-8", true);
	EXPECT_EQ(myDeclarationXML.getType(), exml::nodeType::declaration);
}

TEST(TestDeclarationXML, createCopy) {
	exml::DeclarationXML myDeclarationXML("1.0", "UTF-8", true);
	exml::DeclarationXML myOtherDeclarationXML(myDeclarationXML);
	//EXPECT_EQ(myDeclarationXML, myOtherDeclarationXML);
}

TEST(TestDeclarationXML, createAssignement) {
	exml::DeclarationXML myDeclarationXML("1.0", "UTF-8", true);
	exml::DeclarationXML myOtherDeclarationXML;
	myOtherDeclarationXML = myDeclarationXML;
	//EXPECT_EQ(myDeclarationXML, myOtherDeclarationXML);
}

