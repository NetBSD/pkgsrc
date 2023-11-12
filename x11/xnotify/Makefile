# $NetBSD: Makefile,v 1.10 2023/11/12 13:24:41 wiz Exp $

DISTNAME=	xnotify-0.9.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=phillbush/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/phillbush/xnotify
COMMENT=	Read notifications from stdin and display them on the screen
LICENSE=	mit

CFLAGS.SunOS+=		-D_XOPEN_SOURCE=500

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
