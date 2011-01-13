# $NetBSD: Makefile,v 1.47 2011/01/13 13:40:06 wiz Exp $

DISTNAME=	ruby-gtk-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-gtk-${VERSION}
PKGREVISION=	13
CATEGORIES=	x11 ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-gnome/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://ruby-gnome.sourceforge.net/
COMMENT=	Ruby interface to Gtk+ toolkits
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_VERSION_SUPPORTED= 18
VERSION=		0.34
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=		site-install
DOCS_EN=		README README.EXT doc/rbbr.rb
DOCS_JA=		README.ja README.EXT.ja
INSTALLATION_DIRS==	${RUBY_VENDORLIB} ${RUBY_EG}/gtk/doc \
			${RUBY_EG}/gtk/test ${RUBY_EG}/gtk/testgtk

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
