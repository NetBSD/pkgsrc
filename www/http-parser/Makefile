# $NetBSD: Makefile,v 1.2 2016/05/29 14:17:48 wiz Exp $

DISTNAME=	http-parser-2.7.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nodejs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	schnoebe@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=nodejs/http-parser/}
COMMENT=	Parser for HTTP messages written in C
LICENSE=	mit

USE_LANGUAGES=		c
USE_TOOLS+=		gmake
BUILD_TARGET=		library
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
