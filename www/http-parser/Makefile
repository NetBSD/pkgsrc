# $NetBSD: Makefile,v 1.1 2016/05/28 23:09:30 schnoebe Exp $

DISTNAME=	v${DISTVER}
PKGNAME=	${GITHUB_PROJECT}-${DISTVER}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nodejs/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	schnoebe@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=nodejs/http-parser/}
COMMENT=	Parser for HTTP messages written in C
LICENSE=	mit

GITHUB_PROJECT=	http-parser
DISTVER=	2.7.0

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=		c
USE_TOOLS+=		gmake
BUILD_TARGET=		library
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
