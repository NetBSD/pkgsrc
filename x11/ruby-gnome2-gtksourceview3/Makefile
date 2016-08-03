# $NetBSD: Makefile,v 1.23 2016/08/03 10:23:38 adam Exp $
#

DISTNAME=		gtksourceview3-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
PKGREVISION=		1
COMMENT=		Ruby binding of gtksourceview3
CATEGORIES=		x11

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtksourceview3-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk3>=${VERSION}:../../x11/ruby-gnome2-gtk3

.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
