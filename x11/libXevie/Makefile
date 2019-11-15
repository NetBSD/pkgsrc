# $NetBSD: Makefile,v 1.11 2019/11/15 09:18:17 wiz Exp $

DISTNAME=		libXevie-1.0.3
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Event Interceptor Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config autoconf

PKGCONFIG_OVERRIDE+=	xevie.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

pre-configure:
	cd ${WRKSRC} && autoconf -f

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
