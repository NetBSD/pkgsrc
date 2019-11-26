# $NetBSD: Makefile,v 1.2 2019/11/26 18:32:29 ng0 Exp $

DISTNAME=	nsm-1.20
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=nifty-site-manager/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://www.nift.cc/
COMMENT=	Cross-platform git- and LaTeX-like command-line website manager
LICENSE=	mit

USE_LANGUAGES=		c++
INSTALLATION_DIRS=	bin
BUILD_TARGET=		nsm

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
