# $NetBSD: Makefile,v 1.7 2006/07/20 13:48:14 jlam Exp $
#

DISTNAME=	nqxml-1.1.3p1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/p/./}
PKGREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nqxml/} \
		http://rrr.jin.gr.jp/download/

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=	http://nqxml.sourceforge.net/
COMMENT=	XML parser written in pure Ruby

NO_BUILD=	yes
USE_RUBY_INSTALL= yes

DOC=		README
EXAMPLES=	data.xml doc.xml dumpXML.rb parseTestStream.rb \
		parseTestTree.rb printEntityClassNames.rb \
		reverseTags.rb reverseText.rb write.rb \
		write.rb writeManualDoc.rb writeParsedDoc.rb
CONTRIB_LIB=	autodis_1.rb autodis_2.rb
TESTS=		dispatchertester.rb oasis.rb streamingparsertester.rb test.rb \
		testresource.rb tokenizertester.rb treeparsertester.rb \
		writertester.rb
REPLACE_RUBY_DIRS=	${WRKSRC}/examples ${WRKSRC}/tests

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/nqxml
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/nqxml
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/nqxml/contrib
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/nqxml
.endfor
.for f in ${CONTRIB_LIB}
	${INSTALL_DATA} ${WRKSRC}/contrib/${f} \
		${RUBY_EXAMPLESDIR}/nqxml/contrib
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/nqxml/tests
.for f in ${TESTS}
	${INSTALL_DATA} ${WRKSRC}/tests/${f} ${RUBY_EXAMPLESDIR}/nqxml/tests
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
