# $NetBSD: Makefile,v 1.21 2003/08/31 21:15:07 xtraeme Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
COMMENT=	Small, fast and light-weight window manager (GNOME version)

CONFLICTS+=	icewm-[0-9]* icewm-imlib-[0-9]*

.include "../icewm/Makefile.common"

PLIST_SRC=      ${.CURDIR}/../icewm/PLIST

CONFIGURE_ARGS+=	--with-gnome-menus=yes
CONFIGURE_ARGS+=	--with-imlib=yes
CONFIGURE_ARGS+=	--with-xpm=no

.include "../../graphics/imlib/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
