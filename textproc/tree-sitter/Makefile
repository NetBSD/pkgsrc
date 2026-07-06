# $NetBSD: Makefile,v 1.33 2026/07/06 06:33:07 wiz Exp $

DISTNAME=	tree-sitter-0.26.10
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tree-sitter/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tree-sitter.github.io/
COMMENT=	Incremental parsing system for programming tools
LICENSE=	mit

USE_CC_FEATURES=	c11
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	lib/tree-sitter.pc.in

MAKE_FLAGS+=		PCLIBDIR=${PREFIX}/lib/pkgconfig

CPPFLAGS.SunOS+=	-DHAVE_ENDIAN_H

.include "../../mk/bsd.pkg.mk"
