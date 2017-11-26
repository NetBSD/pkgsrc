# $NetBSD: Makefile,v 1.1 2017/11/26 23:37:18 minskim Exp $

DISTNAME=	rapidjson-1.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Tencent/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rapidjson.org/
COMMENT=	Fast JSON parser/generator with SAX/DOM style API
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++11

PKGCONFIG_OVERRIDE+=	RapidJSON.pc.in

.include "../../mk/bsd.pkg.mk"
