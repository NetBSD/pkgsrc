# $NetBSD: Makefile,v 1.15 2017/09/04 18:08:29 wiz Exp $
#

DISTNAME=	nqxml-1.1.3p1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/p/./}
PKGREVISION=	2
CATEGORIES=	textproc ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nqxml/}

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=	https://sourceforge.net/projects/nqxml/
COMMENT=	XML parser written in pure Ruby
LICENSE=	ruby-license

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
REPLACE_RUBY_DIRS=	examples tests

INSTALL_TARGET=		install \
			--install-dir=${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}
INSTALLATION_DIRS=	${RUBY_DOC}/nqxml ${RUBY_EG}/nqxml/contrib \
			${RUBY_EG}/nqxml/tests

post-install:
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/nqxml
.endfor
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/nqxml
.endfor
.for f in ${CONTRIB_LIB}
	${INSTALL_DATA} ${WRKSRC}/contrib/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/nqxml/contrib
.endfor
.for f in ${TESTS}
	${INSTALL_DATA} ${WRKSRC}/tests/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/nqxml/tests
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
