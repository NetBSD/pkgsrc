# $NetBSD: Makefile,v 1.18 2005/12/05 20:51:09 rillig Exp $

PKGNAME=	${DISTNAME:S/-/-imlib-/}
COMMENT=	Small, fast and light-weight window manager (imlib version)

CONFLICTS+=	icewm-[0-9]* icewm-gnome-[0-9]*

.include "../../wm/icewm/Makefile.common"

PLIST_SRC=		${.CURDIR}/../icewm/PLIST

CONFIGURE_ARGS+=	--with-gnome-menus=no
CONFIGURE_ARGS+=	--with-imlib=yes
CONFIGURE_ARGS+=	--with-xpm=no

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
