# $NetBSD: Makefile,v 1.24 2004/06/26 23:56:21 xtraeme Exp $

PKGNAME=		${DISTNAME}
COMMENT=		Small, fast and light-weight window manager

CONFLICTS+=		icewm-gnome-[0-9]* icewm-imlib-[0-9]*

CONFIGURE_ARGS+=	--with-gnome-menus=no
CONFIGURE_ARGS+=	--with-imlib=no
CONFIGURE_ARGS+=	--with-xpm=${BUILDLINK_PREFIX.xpm}

.include "Makefile.common"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
