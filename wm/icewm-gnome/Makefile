# $NetBSD: Makefile,v 1.8 2002/02/26 09:41:43 martti Exp $

PKGNAME=		${DISTNAME:S/-/-gnome-/}
COMMENT=		Small, fast and light-weight window manager (GNOME version)

CONFLICTS+=		icewm-[0-9]*

USE_BUILDLINK_ONLY=	# defined

.include "../icewm/Makefile.common"

CONFIGURE_ARGS+=	--with-gnome-menus="${GNOME_CONFIG}"
CONFIGURE_ARGS+=	--with-imlib

.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
