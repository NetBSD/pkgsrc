# $NetBSD: Makefile,v 1.3 2020/03/10 22:11:21 wiz Exp $
#

DISTNAME=		vte-${VERSION}
COMMENT=		Ruby binding of vte
PKGREVISION=		2
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
