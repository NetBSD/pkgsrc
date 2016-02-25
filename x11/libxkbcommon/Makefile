# $NetBSD: Makefile,v 1.13 2016/02/25 08:27:05 jperkin Exp $

DISTNAME=	libxkbcommon-0.5.0
CATEGORIES=	x11
MASTER_SITES=	http://xkbcommon.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://xkbcommon.org/
COMMENT=	Library to handle keyboard descriptions
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison gmake pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	xkbcommon.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./xkbcommon.map
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./xkbcommon-x11.map

.include "options.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.10
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
