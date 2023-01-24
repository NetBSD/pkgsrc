# $NetBSD: Makefile,v 1.14 2023/01/24 18:36:35 wiz Exp $

DISTNAME=	pugixml-1.13
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeux/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pugixml.org/
COMMENT=	Light-weight C++ XML processing library
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
