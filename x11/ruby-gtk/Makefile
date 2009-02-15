# $NetBSD: Makefile,v 1.41 2009/02/15 03:34:51 taca Exp $

DISTNAME=	ruby-gtk-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-gtk-${VERSION}
PKGREVISION=	9
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-gnome/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://ruby-gnome.sourceforge.net/
COMMENT=	Ruby interface to Gtk+ toolkits

VERSION=		0.34
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=		site-install
DOCS_EN=		README README.EXT doc/rbbr.rb
DOCS_JA=		README.ja README.EXT.ja
INSTALLATION_DIRS==	${RUBY_VENDORLIB} ${RUBY_EG}/gtk/doc \
			${RUBY_EG}/gtk/test ${RUBY_EG}/gtk/testgtk
PKG_DESTDIR_SUPPORT=	destdir

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${DESTDIR}${PREFIX}/${RUBY_EG}/gtk
	${INSTALL_DATA} ${WRKSRC}/doc/rbbr.rb \
		${DESTDIR}${PREFIX}/${RUBY_EG}/gtk/doc
	${INSTALL_DATA} ${WRKSRC}/sample/test/* ${DESTDIR}${PREFIX}/${RUBY_EG}/gtk/test
	${INSTALL_DATA} ${WRKSRC}/sample/testgtk/* \
		${DESTDIR}${PREFIX}/${RUBY_EG}/gtk/testgtk

.include "../../lang/ruby/modules.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
