# $NetBSD: Makefile,v 1.9 2017/02/15 20:51:57 maya Exp $

DISTNAME=	logswan-1.07
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logswan.org/
COMMENT=	Fast Web log analyzer using probabilistic data structures
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

CMAKE_ARGS+=	-DGEOIPDIR=${PREFIX}/share/GeoIP

do-test:
	logswan ${WRKSRC}/examples/logswan.json

.include "../../textproc/jansson/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
