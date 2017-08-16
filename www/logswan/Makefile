# $NetBSD: Makefile,v 1.10 2017/08/16 20:21:16 wiz Exp $

DISTNAME=	logswan-1.07
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.logswan.org/
COMMENT=	Fast Web log analyzer using probabilistic data structures
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

CMAKE_ARGS+=	-DGEOIPDIR=${PREFIX}/share/GeoIP

do-test:
	logswan ${WRKSRC}/examples/logswan.json

.include "../../textproc/jansson/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
