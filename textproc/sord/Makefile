# $NetBSD: Makefile,v 1.8 2021/01/24 16:27:35 nia Exp $

DISTNAME=	sord-0.16.8
CATEGORIES=	textproc
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/sord/
COMMENT=	Lightweight C library for storing RDF data in memory
LICENSE=	isc

USE_LANGUAGES=	c c++
USE_TOOLS+=	gsed pkg-config

PYTHON_FOR_BUILD_ONLY=	tool
PKGCONFIG_OVERRIDE+=	sord.pc.in

.include "options.mk"
.include "../../devel/waf/waf.mk"
.include "../../devel/pcre/buildlink3.mk"
BUILDLINK_API_DEPENDS.serd+=	serd>=0.30.0
.include "../../textproc/serd/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
