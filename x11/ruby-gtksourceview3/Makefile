# $NetBSD: Makefile,v 1.11 2022/01/17 15:17:16 tsutsui Exp $
#

DISTNAME=		gtksourceview3-${VERSION}
COMMENT=		Ruby binding of gtksourceview3
CATEGORIES=		x11

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-gtksourceview3-[0-9]*
SUPERSEDES+=		ruby-gnome2-gtksourceview3-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gobject-introspection>=${VERSION}:../../devel/ruby-gobject-introspection
DEPENDS+=		${RUBY_PKGPREFIX}-gtk3>=${VERSION}:../../x11/ruby-gtk3

.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
