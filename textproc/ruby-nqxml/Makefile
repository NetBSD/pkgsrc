# $NetBSD: Makefile,v 1.1.1.1 2002/01/27 15:27:28 taca Exp $
#

DISTNAME=	nqxml-1.1.3p1
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME:S/p/./}
CATEGORIES=	textproc
MASTER_SITES=	http://rrr.jin.gr.jp/download/ \
		http://www.io.com/~jimm/downloads/nqxml/

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=	http://www.io.com/~jimm/downloads/nqxml/index.html
COMMENT=	XML parser written in pure Ruby

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	yes

DOC=		README
EXAMPLES=	data.xml doc.xml dumpXML.rb parseTestStream.rb \
		parseTestTree.rb printEntityClassNames.rb \
		reverseTags.rb reverseText.rb write.rb \
		write.rb writeManualDoc.rb writeParsedDoc.rb
CONTRIB_LIB=	autodis_1.rb autodis_2.rb
TESTS=		dispatchertester.rb oasis.rb streamingparsertester.rb test.rb \
		testresource.rb tokenizertester.rb treeparsertester.rb \
		writertester.rb
REPLACE_RUBY=	examples/dumpXML.rb examples/parseTestStream.rb \
		examples/parseTestTree.rb examples/printEntityClassNames.rb \
		examples/reverseTags.rb examples/reverseText.rb \
		examples/write.rb examples/writeManualDoc.rb \
		examples/writeParsedDoc.rb tests/oasis.rb tests/test.rb

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/nqxml
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/nqxml
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/nqxml/contrib
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/$f ${RUBY_EXAMPLESDIR}/nqxml
.endfor
.for f in ${CONTRIB_LIB}
	${INSTALL_DATA} ${WRKSRC}/contrib/$f ${RUBY_EXAMPLESDIR}/nqxml/contrib
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/nqxml/tests
.for f in ${TESTS}
	${INSTALL_DATA} ${WRKSRC}/tests/$f ${RUBY_EXAMPLESDIR}/nqxml/tests
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
