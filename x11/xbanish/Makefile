# $NetBSD: Makefile,v 1.5 2022/07/07 21:32:21 pin Exp $

DISTNAME=	xbanish-1.8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=jcs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://github.com/jcs/xbanish
COMMENT=	Banish the mouse cursor when typing
LICENSE=	isc

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	LDPATH=${X11_LDFLAGS:Q}\ ${LDFLAGS:Q}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
