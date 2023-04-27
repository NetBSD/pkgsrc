# $NetBSD: Makefile,v 1.7 2023/04/27 08:19:09 wiz Exp $

DISTNAME=	tinyxml2-9.0.0
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
