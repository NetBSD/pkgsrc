# $NetBSD: Makefile,v 1.4 2003/07/16 09:23:29 tron Exp $

PKGNAME=	${DISTNAME:S/-/-imlib-/}
PKGREVISION=	2
COMMENT=	Small, fast and light-weight window manager (GNOME version)

CONFLICTS+=	icewm-[0-9]* icewm-gnome-[0-9]*

.include "../icewm/Makefile.common"

PLIST_SRC=		${.CURDIR}/../icewm/PLIST

CONFIGURE_ARGS+=	--with-gnome-menus=no
CONFIGURE_ARGS+=	--with-imlib=yes
CONFIGURE_ARGS+=	--with-xpm=no

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
