# $NetBSD: Makefile,v 1.4 2002/01/04 00:13:06 taca Exp $

DISTNAME=	rttool-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www.ruby-lang.org/~rubikitch/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/~rubikitch/computer/rt.html
COMMENT=	RT to HTML (and hopefully LaTeX in future) table converter

DEPENDS+=	${RUBY_PKGNAMEPREFIX}optparse>=0.7:../../devel/ruby-optparse
DEPENDS+=	w3m>=0.2.1:../../www/w3m

DIST_SUBDIR=	ruby
VERSION=	0.1.7
RUBY_REQD=	1.6.0
USE_RUBY_SETUP=	# defined

REPLACE_RUBY=	bin/rt/rt2 lib/rt/rt2html-lib.rb lib/rt/rt2txt-lib.rb \
		lib/rt/rtparser-test.rb lib/rt/rtparser.rb \
		lib/rt/rtvisitor.rb lib/rt/w3m.rb

#DOCS=		rt.html rt.rd
EXAMPLES=	rttest.rd test1.rt test2.rt

pre-configure:
	${RM} -f ${WRKSRC}/setup/rt.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/rt
	${INSTALL_DATA} ${WRKSRC}/rt.html ${RUBY_DOCDIR}/rt/rt.ja.html
	${INSTALL_DATA} ${WRKSRC}/rt.rd ${RUBY_DOCDIR}/rt/rt.ja.rd
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/rt
	${INSTALL_DATA} ${WRKSRC}/dot.rt.rd2rc ${RUBY_EXAMPLESDIR}/rt
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/rt
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
