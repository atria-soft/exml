/**
 * @author Edouard DUPIN
 * 
 * @copyright 2014, Edouard DUPIN, all right reserved
 * 
 * @license APACHE v2.0 (see license file)
 */


#ifndef __EXML_TEST_ALL_H__
#define __EXML_TEST_ALL_H__

#include "exmlTestCommon.h"
#include <gtest/gtest.h>


TEST(TestAll, testBase) {
	exmlLocalTest( "<exemple>\n"
	               "	<ex2 ploppp-plpl:erer=\"dfsdfsdfsdf\" lkmjmlk=\"156235\" sdfsdf=\"456321\"/>\n"
	               "	<exlkjl-_dsfg./>\n"
	               "	<ex2>Text example ...</ex2>\n"
	               "</exemple>\n",
	               "<   	 		 exemple\n   	>\n"
	               "	<ex2 ploppp-plpl:erer=\"dfsdfsdfsdf\" lkmjmlk=\"156235\" sdfsdf=456321     />\n"
	               "	<exlkjl-_dsfg./>\n"
	               "	<ex2>\n"
	               "		Text example ...\n"
	               "	</ex2>\n"
	               "</exemple>\n",
	              -1);
}
TEST(TestAll, testError) {
	exmlLocalTest( "",
	               "<   	 		 exemple\n   	>\n"
	               "	<ex2 ploppp-plpl:erer=\"dfsdfsdfsdf\" lkmjmlk=\"156235\" sdfsdf=456321     />\n"
	               "	<exlkjl-_dsfg./>    >\n"
	               "	<ex2>\n"
	               "		Text example ...\n"
	               "	</ex2>\n"
	               "</exemple>\n",
	               1);
}


#endif