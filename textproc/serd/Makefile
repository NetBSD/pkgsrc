# $NetBSD: Makefile,v 1.12 2023/08/14 05:25:24 wiz Exp $

DISTNAME=	serd-0.30.12
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/serd/
COMMENT=	Lightweight C library for RDF syntax
LICENSE=	isc

USE_LANGUAGES=	c99
USE_TOOLS+=	gsed pkg-config

PYTHON_FOR_BUILD_ONLY=	tool
PKGCONFIG_OVERRIDE+=	serd.pc.in

.include "options.mk"
.include "../../devel/waf/waf.mk"
.include "../../mk/bsd.pkg.mk"
