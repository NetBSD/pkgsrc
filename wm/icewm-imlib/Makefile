# $NetBSD: Makefile,v 1.15 2005/01/13 01:31:53 xtraeme Exp $

PKGNAME=	${DISTNAME:S/-/-imlib-/}
PKGREVISION=	3
COMMENT=	Small, fast and light-weight window manager (imlib version)

CONFLICTS+=	icewm-[0-9]* icewm-gnome-[0-9]*

.include "../icewm/Makefile.common"

PLIST_SRC=		${.CURDIR}/../icewm/PLIST

CONFIGURE_ARGS+=	--with-gnome-menus=no
CONFIGURE_ARGS+=	--with-imlib=yes
CONFIGURE_ARGS+=	--with-xpm=no

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
