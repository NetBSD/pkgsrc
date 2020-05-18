# $NetBSD: Makefile,v 1.8 2020/05/18 10:26:13 nia Exp $

DISTNAME=	serd-0.30.4
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
