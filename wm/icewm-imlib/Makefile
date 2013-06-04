# $NetBSD: Makefile,v 1.39 2013/06/04 22:17:13 tron Exp $

PKGNAME=		${DISTNAME:S/-/-imlib-/}
PKGREVISION=		12
COMMENT=		Small, fast and light-weight window manager (imlib version)

CONFLICTS+=		icewm-[0-9]* icewm-gnome-[0-9]*

.include "../../wm/icewm/Makefile.common"

PLIST_SRC=		${.CURDIR}/../icewm/PLIST

CONFIGURE_ARGS+=	--with-gnome-menus=no
CONFIGURE_ARGS+=	--with-imlib=yes
CONFIGURE_ARGS+=	--with-xpm=no

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
