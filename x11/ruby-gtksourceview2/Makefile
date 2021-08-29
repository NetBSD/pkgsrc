# $NetBSD: Makefile,v 1.10 2021/08/29 17:08:47 tsutsui Exp $
#

DISTNAME=		gtksourceview2-3.4.3
PKGREVISION=		1
CATEGORIES=		x11

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ruby-gnome2.osdn.jp/
COMMENT=		Ruby binding of gtksourceview2
LICENSE=		gnu-lgpl-v2.1

CONFLICTS+=		ruby-gnome2-gtksourceview2-[0-9]*
SUPERSEDES+=		ruby-gnome2-gtksourceview2-[0-9]*

.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/ruby-gtk2/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
