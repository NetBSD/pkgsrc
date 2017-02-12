# $NetBSD: Makefile,v 1.26 2017/02/12 06:26:15 ryoon Exp $
#

DISTNAME=		gtksourceview3-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
PKGREVISION=		2
COMMENT=		Ruby binding of gtksourceview3
CATEGORIES=		x11

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtksourceview3-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk3>=${VERSION}:../../x11/ruby-gnome2-gtk3

.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
