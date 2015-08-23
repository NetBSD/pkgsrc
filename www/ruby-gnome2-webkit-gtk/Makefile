# $NetBSD: Makefile,v 1.5 2015/08/23 10:17:55 wiz Exp $

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-webkit-gtk-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of WebKitGTK+
CATEGORIES=		www

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk3>=${VERSION}:../../x11/ruby-gnome2-gtk3
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	webkit24-gtk3>=1.10.2nb6:../../www/webkit24-gtk3

RUBY_SETUP_SUBDIRS=	webkit-gtk
USE_RUBY_EXTCONF=	no
USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
