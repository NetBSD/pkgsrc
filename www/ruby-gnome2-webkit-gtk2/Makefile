# $NetBSD: Makefile,v 1.1 2013/06/15 09:39:34 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-webkit-gtk-${VERSION}
COMMENT=		Ruby binding of WebKitGTK+ for GTK2+
CATEGORIES=		www

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	webkit-gtk>=1.10.2nb8:../../www/webkit-gtk

RUBY_SETUP_SUBDIRS=	webkit-gtk2
USE_RUBY_EXTCONF=	no
USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
