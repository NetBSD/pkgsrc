# $NetBSD: Makefile,v 1.8 2016/01/24 05:03:24 tsutsui Exp $
#

DISTNAME=		webkit-gtk2-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
PKGREVISION=		1
COMMENT=		Ruby binding of WebKitGTK+ for GTK2+
CATEGORIES=		www

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	webkit24-gtk>=1.10.2nb8:../../www/webkit24-gtk

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
