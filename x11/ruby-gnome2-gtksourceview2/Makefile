# $NetBSD: Makefile,v 1.59 2018/11/14 22:22:50 kleink Exp $
#

DISTNAME=		gtksourceview2-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
PKGREVISION=		2
COMMENT=		Ruby binding of gtksourceview2
CATEGORIES=		x11

MAINTAINER=		pkgsrc-users@NetBSD.org

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/ruby-gnome2-gtk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
