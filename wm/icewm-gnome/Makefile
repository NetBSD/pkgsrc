# $NetBSD: Makefile,v 1.31 2005/01/13 10:14:45 xtraeme Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	2
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
