# $NetBSD: Makefile,v 1.9 2002/02/27 13:54:27 tron Exp $

PKGNAME=		${DISTNAME:S/-/-gnome-/:S/-2/.2/}
COMMENT=		Small, fast and light-weight window manager (GNOME version)

CONFLICTS+=		icewm-[0-9]*

USE_BUILDLINK_ONLY=	# defined

.include "../icewm/Makefile.common"

CONFIGURE_ARGS+=	--with-gnome-menus="${GNOME_CONFIG}"
CONFIGURE_ARGS+=	--with-imlib

.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
