# $NetBSD: Makefile,v 1.14 2016/02/26 11:27:15 jperkin Exp $

DISTNAME=	libXinerama-1.1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	X PanoramiX extension library

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	xinerama.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
BUILDLINK_API_DEPENDS.xineramaproto+=	xineramaproto>=1.1.99.1
.include "../../x11/xineramaproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
