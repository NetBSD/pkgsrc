# $NetBSD: Makefile,v 1.50 2020/03/22 10:08:38 rillig Exp $

COMMENT=		Small, fast and light-weight window manager
PKGREVISION=		2

CONFLICTS+=		icewm-gnome-[0-9]* icewm-imlib-[0-9]*

CONFIGURE_ARGS+=	--with-imlib=no
CONFIGURE_ARGS+=	--with-xpm=${BUILDLINK_PREFIX.libXpm}

.include "Makefile.common"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
