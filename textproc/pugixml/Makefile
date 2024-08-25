# $NetBSD: Makefile,v 1.16 2024/08/25 06:19:17 wiz Exp $

DISTNAME=	pugixml-1.14
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeux/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pugixml.org/
COMMENT=	Light-weight C++ XML processing library
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
