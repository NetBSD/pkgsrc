# $NetBSD: Makefile,v 1.3 2016/06/09 06:23:41 wiz Exp $

DISTNAME=	http-parser-2.7.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nodejs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	schnoebe@NetBSD.org
HOMEPAGE=	https://github.com/nodejs/http-parser/
COMMENT=	Parser for HTTP messages written in C
LICENSE=	mit

USE_LANGUAGES=		c
USE_TOOLS+=		gmake
BUILD_TARGET=		library
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
