# $NetBSD: Makefile,v 1.8 2021/12/08 16:07:14 adam Exp $
#

DISTNAME=		vte-3.4.3
PKGREVISION=		2
CATEGORIES=		x11

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ruby-gnome2.osdn.jp/
COMMENT=		Ruby binding of vte
LICENSE=		gnu-lgpl-v2.1

CONFLICTS+=		ruby-gnome2-vte-[0-9]*
SUPERSEDES+=		ruby-gnome2-vte-[0-9]*

.include "../../x11/ruby-gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
