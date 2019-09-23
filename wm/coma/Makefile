# $NetBSD: Makefile,v 1.4 2019/09/23 14:57:12 fcambus Exp $

DISTNAME=	coma-1.0
CATEGORIES=	wm
MASTER_SITES=	https://coma.one/releases/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://coma.one/releases/
COMMENT=	Keyboard driven tiling window manager
LICENSE=	isc

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	MAN_DIR="${PREFIX}/${PKGMANDIR}"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
