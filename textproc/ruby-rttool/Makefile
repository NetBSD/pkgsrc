# $NetBSD: Makefile,v 1.10 2005/03/06 17:19:07 taca Exp $

DISTNAME=	rttool-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.rubyist.net/~rubikitch/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.rubyist.net/~rubikitch/computer/rt/
COMMENT=	RT to HTML (and hopefully LaTeX in future) table converter

CONFLICTS+=	ruby[1-9][0-9]-rttool-*

VERSION=	0.1.8
USE_RUBY_SETUP=	yes
REPLACE_RUBY=	bin/rt/rt2 lib/rt/rt2html-lib.rb \
		lib/rt/rt2txt-lib.rb lib/rt/rtparser.rb \
		lib/rt/rtvisitor.rb lib/rt/w3m.rb
EXAMPLES=	rttest.rd test1.rt test2.rt

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == 16
DEPENDS+=	${RUBY_PKGPREFIX}-optparse>=0.7:../../devel/ruby-optparse
.endif

pre-configure:
	${RM} -f ${WRKSRC}/setup/rt.rb ${WRKSRC}/lib/rt/rtparser-test.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/rt
	${INSTALL_DATA} ${WRKSRC}/rt.html ${RUBY_DOCDIR}/rt/rt.ja.html
	${INSTALL_DATA} ${WRKSRC}/rt.rd ${RUBY_DOCDIR}/rt/rt.ja.rd
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/rt
	${INSTALL_DATA} ${WRKSRC}/dot.rt.rd2rc ${RUBY_EXAMPLESDIR}/rt
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/rt
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
