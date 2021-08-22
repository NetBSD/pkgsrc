# $NetBSD: Makefile,v 1.6 2021/08/22 17:02:44 tsutsui Exp $
#

VERSION=		3.4.3
DISTNAME=		vte-${VERSION}
CATEGORIES=		x11

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ruby-gnome2.osdn.jp/
COMMENT=		Ruby binding of vte
LICENSE=		gnu-lgpl-v2.1

CONFLICTS+=		ruby-gnome2-vte-[0-9]*
SUPERSEDES+=		ruby-gnome2-vte-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gtk2>=${VERSION}:../../x11/ruby-gtk2

.include "../../x11/ruby-gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
