# $NetBSD: Makefile,v 1.3 2015/05/11 14:21:29 mef Exp $

DISTNAME=	tinyxml2-2.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=leethomason/}
GITHUB_PROJECT=	tinyxml2
GITHUB_TAG=	2.2.0
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.grinninglizard.com/tinyxml2/
COMMENT=	Simple, small and efficient C++ XML parser
LICENSE=	zlib

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=tinyxml2.pc.in

.include "../../mk/bsd.pkg.mk"
