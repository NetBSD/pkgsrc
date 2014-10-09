# $NetBSD: Makefile,v 1.14 2014/10/09 14:07:15 wiz Exp $

DISTNAME=		libXv-1.0.10
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xv Extension library

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xv.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-malloc0returnsnull
.endif

.include "../../meta-pkgs/modular-xorg/hacks.mk"

BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
