# $NetBSD: Makefile,v 1.19 2012/09/27 10:06:31 jperkin Exp $

DISTNAME=	xf86-video-radeonhd-1.3.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://wiki.x.org/wiki/radeonhd
COMMENT=	Modular X.org driver for Radeon HD series

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ENV+=	ac_cv_file___src_AtomBios_includes_atombios_h=yes
CONFIGURE_ENV+=	ac_cv_file___src_AtomBios_includes_Decoder_h=yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DRIVER_MAN_SUFFIX=4
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
