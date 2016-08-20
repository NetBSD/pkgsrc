# $NetBSD: Makefile,v 1.22 2016/08/20 14:48:18 kamil Exp $

DISTNAME=	xf86-input-vmmouse-13.1.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular Xorg VMware virtual mouse driver

USE_LANGUAGES=	c99
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

# Currently libudev is unsupported in pkgsrc
CONFIGURE_ARGS+=	--without-libudev

.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
