# $NetBSD: Makefile,v 1.5 2020/08/17 20:20:36 leot Exp $
#

DISTNAME=		vte-${VERSION}
COMMENT=		Ruby binding of vte
PKGREVISION=		1
CATEGORIES=		x11

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-vte-[0-9]*
SUPERSEDES+=		ruby-gnome2-vte-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gtk2>=${VERSION}:../../x11/ruby-gtk2

.include "../../x11/ruby-gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
