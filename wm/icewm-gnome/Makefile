# $NetBSD: Makefile,v 1.15 2003/05/02 11:56:36 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	2
COMMENT=	Small, fast and light-weight window manager (GNOME version)

CONFLICTS+=	icewm-[0-9]*

USE_BUILDLINK2=		# defined

.include "../icewm/Makefile.common"

CONFIGURE_ARGS+=	--with-imlib

pre-configure:
	cd ${WRKSRC};	\
	${MV} src/default.h src/default.h.orig;	\
	${SED} 's/XIV(bool, autoDetectGnome,			false)/XIV(bool, autoDetectGnome,			true)/' \
		< src/default.h.orig > src/default.h

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
