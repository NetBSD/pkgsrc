# $NetBSD: Makefile,v 1.22 2004/01/03 18:49:54 reed Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	1
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
