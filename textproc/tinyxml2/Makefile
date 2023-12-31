# $NetBSD: Makefile,v 1.8 2023/12/31 21:36:45 wiz Exp $

DISTNAME=	tinyxml2-10.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=leethomason/}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://leethomason.github.io/tinyxml2/
COMMENT=	Simple, small and efficient C++ XML parser
LICENSE=	zlib

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=	tinyxml2.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
