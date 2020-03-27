# $NetBSD: Makefile,v 1.7 2020/03/27 08:57:59 nia Exp $

DISTNAME=	pugixml-1.10
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeux/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pugixml.org/
COMMENT=	Light-weight C++ XML processing library
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/bsd.pkg.mk"
