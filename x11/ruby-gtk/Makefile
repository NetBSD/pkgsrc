# $NetBSD: Makefile,v 1.15 2002/03/21 04:23:38 fredb Exp $
# FreeBSD: ports/x11-toolkits/ruby-gtk/Makefile,v 1.16 2000/10/15 15:45:59 knu Exp

DISTNAME=	ruby-gtk-0.25
PKGNAME=	${RUBY_PKGNAMEPREFIX}gtk-0.25
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.ruby-lang.org/gtk/download/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/gtk/en/
COMMENT=	Ruby interface to Gtk+ toolkits

DEPENDS+=	lang/ruby-base>=1.6.7nb1:../../lang/ruby-base

WRKSRC=		${WRKDIR}/${DISTNAME:S/ruby-//}

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes

INSTALL_TARGET=	site-install

DEPENDS+=	imlib>=1.9.11nb1:../../graphics/imlib

DOCS_EN=	README README.EXT doc/rbbr.rb
DOCS_JA=	README.ja README.EXT.ja

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb)

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gtk
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/gtk
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gtk/doc
	${INSTALL_DATA} ${WRKSRC}/doc/rbbr.rb \
		${RUBY_EXAMPLESDIR}/gtk/doc
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gtk/test
	${INSTALL_DATA} ${WRKSRC}/sample/test/* ${RUBY_EXAMPLESDIR}/gtk/test
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gtk/testgtk
	${INSTALL_DATA} ${WRKSRC}/sample/testgtk/* \
		${RUBY_EXAMPLESDIR}/gtk/testgtk

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
