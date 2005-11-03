# $NetBSD: Makefile,v 1.12 2005/11/03 05:26:10 taca Exp $

DISTNAME=	rttool-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.rubyist.net/~rubikitch/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.rubyist.net/~rubikitch/computer/rt/
COMMENT=	RT to HTML (and hopefully LaTeX in future) table converter

CONFLICTS+=	ruby[1-9][0-9]-rttool-*

VERSION=		1.0.1
USE_RUBY_DIST_SUBDIR=	yes
USE_RUBY_SETUP=		yes
REPLACE_RUBY_DIRS=	${WRKSRC}/bin/rt ${WRKSRC}/lib/rt
HTMLDOCS=		rttool.en.html rttool.ja.html
DOCS=			rttool.en.rd rttool.ja.rd
SRCS=			rt2html-lib.rb rt2txt-lib.rb rtparser.rb \
			rtvisitor.rb w3m.rb

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == 16
DEPENDS+=	${RUBY_PKGPREFIX}-optparse>=0.7:../../devel/ruby-optparse
.endif

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/rt
.for f in ${DOCS} ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rt
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rt
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/rt
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/rt

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
