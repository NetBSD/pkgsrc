# $NetBSD: Makefile,v 1.7 2001/10/24 22:11:09 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-gnome-/}
COMMENT=		small, fast and light-weight window manager (GNOME version)

CONFLICTS+=		icewm-[0-9]*

USE_BUILDLINK_ONLY=	# defined

.include "../icewm/Makefile.common"

CONFIGURE_ARGS+=	--with-gnome-menus="${GNOME_CONFIG}"
CONFIGURE_ARGS+=	--with-imlib

.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
