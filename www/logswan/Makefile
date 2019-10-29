# $NetBSD: Makefile,v 1.13 2019/10/29 09:18:08 fcambus Exp $

DISTNAME=	logswan-2.1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://www.logswan.org/
COMMENT=	Fast Web log analyzer using probabilistic data structures
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

CMAKE_ARGS+=	-DGEOIP2DIR=${PREFIX}/share/GeoIP

do-test:
	${RUN} cd ${WRKSRC} && ./${PKGBASE} examples/${PKGBASE}.log

.include "../../textproc/jansson/buildlink3.mk"
.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
