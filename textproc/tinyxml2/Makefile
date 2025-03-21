# $NetBSD: Makefile,v 1.11 2025/03/21 16:43:53 wiz Exp $

DISTNAME=	tinyxml2-11.0.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=leethomason/}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://leethomason.github.io/tinyxml2/
COMMENT=	Simple, small and efficient C++ XML parser
LICENSE=	zlib

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-Dtinyxml2_SHARED_LIBS=ON

PKGCONFIG_OVERRIDE=	cmake/tinyxml2.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
