/*
 * LinkIconsRetriever.h
 *
 *  Created on: Jun 27, 2023
 *      Author: David Yockey
 *
 * MIT License
 *
 * Copyright © 2023 David Yockey
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SRC_LINKICONSRETRIEVER_HPP_
#define SRC_LINKICONSRETRIEVER_HPP_

#include <htmlcxx/html/ParserDom.h>
#include "IconsRetriever.hpp"

using namespace htmlcxx;

class LinkIconsRetriever : IconsRetriever {
private:
	typedef tree<HTML::Node>::iterator nodeItr;

	string html;

	std::set<string> rels = {
			"shortcut icon", "icon", "mask-icon", "apple-touch-icon", "apple-touch-icon-precomposed",	/* standard rel values */
			"alternate icon" /* discovered on github.com */

	};

	string siteurl;

//	bool	notSubStr		(string str, int pos, int count, string cmp );
//	string	finishURL		(string url);
	string	getAttrText		(nodeItr itr, string attr);
	void	procLinkIconTag	(nodeItr itr, ficonvector& ficons);
	void	getLinkIconTags	(ficonvector& ficons);

	string	pulledsite_url;	// may differ from url used in Curler pull call if 3xx redirection was performed

public:
	LinkIconsRetriever();
	void pull(string url, ficonvector& ficons);
	virtual ~LinkIconsRetriever();
};

#endif /* SRC_LINKICONSRETRIEVER_HPP_ */
