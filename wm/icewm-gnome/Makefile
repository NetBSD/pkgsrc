# $NetBSD: Makefile,v 1.12 2002/08/22 10:58:40 martti Exp $

PKGNAME=		${DISTNAME:S/-/-gnome-/}
COMMENT=		Small, fast and light-weight window manager (GNOME version)

CONFLICTS+=		icewm-[0-9]*

USE_BUILDLINK_ONLY=	# defined

.include "../icewm/Makefile.common"

CONFIGURE_ARGS+=	--with-gnome-menus="${GNOME_CONFIG}"
CONFIGURE_ARGS+=	--with-imlib

pre-configure:
	cd ${WRKSRC};	\
	${MV} src/default.h src/default.h.orig;	\
	${SED} 's/XIV(bool, autoDetectGnome,			false)/XIV(bool, autoDetectGnome,			true)/' \
		< src/default.h.orig > src/default.h

.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
