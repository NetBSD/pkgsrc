# $NetBSD: Makefile,v 1.9 2012/10/29 05:06:33 asau Exp $
#

DISTNAME=		libXScrnSaver-1.2.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 Screen Saver Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=		scrnsaverproto<1.2.0

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xscrnsaver.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-malloc0returnsnull
.endif

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
BUILDLINK_API_DEPENDS.scrnsaverproto+=	scrnsaverproto>=1.2.0
.include "../../x11/scrnsaverproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
