# $NetBSD: Makefile,v 1.1 2026/07/04 11:49:00 gdt Exp $

VERSION=	0.20.1
DISTNAME=	blogc-${VERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=blogc/}
GITHUB_PROJECT=	blogc
GITHUB_RELEASE=	v${VERSION}

MAINTAINER=	kj4ntv@gmail.com
HOMEPAGE=	https://blogc.rgm.io/
COMMENT=	Single-page blog compiler
LICENSE=	modified-bsd

USE_CC_FEATURES+=	c99

TEST_TARGET=	check
# Tools used by test but not build.
USE_TOOLS+=	bash diff tee

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
