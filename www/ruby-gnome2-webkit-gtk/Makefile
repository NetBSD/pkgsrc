# $NetBSD: Makefile,v 1.1 2013/06/15 09:39:34 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-webkit-gtk-${VERSION}
COMMENT=		Ruby binding of WebKitGTK+
CATEGORIES=		www

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk3>=${VERSION}:../../x11/ruby-gnome2-gtk3
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	webkit-gtk3>=1.10.2nb6:../../www/webkit-gtk3

RUBY_SETUP_SUBDIRS=	webkit-gtk
USE_RUBY_EXTCONF=	no
USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
