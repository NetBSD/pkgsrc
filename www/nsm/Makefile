# $NetBSD: Makefile,v 1.1 2019/10/22 10:34:34 ng0 Exp $

DISTNAME=	nsm-1.15
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
