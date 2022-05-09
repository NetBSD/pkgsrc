# $NetBSD: Makefile,v 1.26 2022/05/09 17:07:08 nikita Exp $

DISTNAME=	cwm-7.1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://github.com/leahneukirchen/cwm
COMMENT=	Portable version of the window manager from OpenBSD
LICENSE=	isc

EXTRACT_USING=	gtar
USE_TOOLS+=	pkg-config yacc

INSTALL_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
