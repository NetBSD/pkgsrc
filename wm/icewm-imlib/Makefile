# $NetBSD: Makefile,v 1.25 2006/05/18 20:30:01 wiz Exp $

PKGNAME=		${DISTNAME:S/-/-imlib-/}
COMMENT=		Small, fast and light-weight window manager (imlib version)

CONFLICTS+=		icewm-[0-9]* icewm-gnome-[0-9]*

BROKEN_IN=		pkgsrc-2006Q1

.include "../../wm/icewm/Makefile.common"

PLIST_SRC=		${.CURDIR}/../icewm/PLIST

CONFIGURE_ARGS+=	--with-gnome-menus=no
CONFIGURE_ARGS+=	--with-imlib=yes
CONFIGURE_ARGS+=	--with-xpm=no

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
