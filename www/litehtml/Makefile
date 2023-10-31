# $NetBSD: Makefile,v 1.4 2023/10/31 12:53:52 nros Exp $

DISTNAME=	litehtml-0.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=litehtml/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.litehtml.com/
COMMENT=	Fast and lightweight HTML/CSS rendering engine
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++11

CMAKE_CONFIGURE_ARGS+=	-DEXTERNAL_GUMBO=ON
# Turn off testing since it installs gtest
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING:BOOL=OFF

CMAKE_USE_GNU_INSTALL_DIRS=	no

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

# conform with the BSD license when distributing
post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/cmake/build.mk"
.include "../../www/gumbo-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
