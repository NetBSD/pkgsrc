# $NetBSD: Makefile,v 1.11 2019/01/17 21:56:09 kamil Exp $

DISTNAME=	logswan-2.0.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}

MAINTAINER=	fred@statdns.com
HOMEPAGE=	https://www.logswan.org/
COMMENT=	Fast Web log analyzer using probabilistic data structures
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

CMAKE_ARGS+=	-DGEOIP2DIR=${PREFIX}/share/GeoIP

do-test:
	logswan ${WRKSRC}/examples/logswan.json

.include "../../textproc/jansson/buildlink3.mk"
.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
