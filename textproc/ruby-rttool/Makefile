# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 14:00:22 taca Exp $

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
VERSION=	0.1.3
NO_BUILD=	# yes

REPLACE_RUBY=	rt/rt2

RT_COMMANDS=	rt2 rdrt2
RT_LIB=		rt2html-lib.rb rt2txt-lib.rb rtparser.rb rtvisitor.rb w3m.rb

DOCS_JA=	rt.html rt.rd

do-install:
.for f in ${RT_COMMANDS}
	${INSTALL_SCRIPT} ${WRKSRC}/rt/${f} ${LOCALBASE}/bin
.endfor
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/rt
.for f in ${RT_LIB}
	${INSTALL_DATA} ${WRKSRC}/rt/${f} ${RUBY_SITELIBDIR}/rt
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/rt/ja
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rt/ja
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/rt
	${INSTALL_DATA} ${WRKSRC}/rt/dot.rt.rd2rc ${RUBY_EXAMPLESDIR}/rt

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
