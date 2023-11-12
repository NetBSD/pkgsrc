# $NetBSD: Makefile,v 1.19 2023/11/12 13:24:34 wiz Exp $

DISTNAME=	xf86-video-ati-6.14.6
PKGNAME=	${DISTNAME:S/ati/ati6/}
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI Radeon video driver (v6)

CONFIGURE_ARGS+=	--enable-dri

CONFLICTS+=	xf86-video-ati-[0-9]*

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	automake autoconf autoreconf gmake pkg-config

RELRO_SUPPORTED=	partial

.include "options.mk"

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
