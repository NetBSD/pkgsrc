# $NetBSD: Makefile,v 1.28 2004/10/03 00:18:23 tv Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	1
COMMENT=	Small, fast and light-weight window manager (GNOME version)

CONFLICTS+=	icewm-[0-9]* icewm-imlib-[0-9]*

.include "../icewm/Makefile.common"

PLIST_SRC=      ${.CURDIR}/../icewm/PLIST

CONFIGURE_ARGS+=	--with-gnome-menus=yes
CONFIGURE_ARGS+=	--with-imlib=yes
CONFIGURE_ARGS+=	--with-xpm=no

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
