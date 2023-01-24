# $NetBSD: Makefile,v 1.6 2023/01/24 18:36:35 wiz Exp $

DISTNAME=	tinyxml2-2.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=leethomason/}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.grinninglizard.com/tinyxml2/
COMMENT=	Simple, small and efficient C++ XML parser
LICENSE=	zlib

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=	tinyxml2.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
