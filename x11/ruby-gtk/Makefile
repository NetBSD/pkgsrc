# $NetBSD: Makefile,v 1.29 2005/01/28 14:08:02 taca Exp $
# FreeBSD: ports/x11-toolkits/ruby-gtk/Makefile,v 1.16 2000/10/15 15:45:59 knu Exp

DISTNAME=	ruby-gtk-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-gtk-${VERSION}
PKGREVISION=	1
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-gnome/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://ruby-gnome.sourceforge.net/
COMMENT=	Ruby interface to Gtk+ toolkits

VERSION=		0.34
RUBY_HAS_ARCHLIB=	yes
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
USE_X11=		yes
INSTALL_TARGET=		site-install
DOCS_EN=		README README.EXT doc/rbbr.rb
DOCS_JA=		README.ja README.EXT.ja

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

.include "../../lang/ruby/modules.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
