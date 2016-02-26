# $NetBSD: Makefile,v 1.7 2016/02/26 11:27:19 jperkin Exp $

DISTNAME=	xf86-video-newport-0.2.4
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Unaccelerated driver for the SGI newport cards (a.k.a. XL)
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

USE_OLD_MODULAR_XORG_SERVER=		yes

.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
