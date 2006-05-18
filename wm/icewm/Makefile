# $NetBSD: Makefile,v 1.33 2006/05/18 20:30:01 wiz Exp $

PKGNAME=		${DISTNAME}
COMMENT=		Small, fast and light-weight window manager

CONFLICTS+=		icewm-gnome-[0-9]* icewm-imlib-[0-9]*

CONFIGURE_ARGS+=	--with-gnome-menus=no
CONFIGURE_ARGS+=	--with-imlib=no
CONFIGURE_ARGS+=	--with-xpm=${BUILDLINK_PREFIX.xpm}

BROKEN_IN=		pkgsrc-2006Q1

.include "Makefile.common"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
