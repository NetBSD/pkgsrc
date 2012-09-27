# $NetBSD: Makefile,v 1.10 2012/09/27 10:06:32 jperkin Exp $
#

DISTNAME=	xf86-video-vga-4.1.0
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg generic VGA video driver

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf autoheader automake autoreconf pkg-config

BUILD_DEPENDS+=	xorg-util-macros>=1.2.0:../../devel/xorg-util-macros

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXext?=	build
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
