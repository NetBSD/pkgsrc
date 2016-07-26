# $NetBSD: Makefile,v 1.5 2016/07/26 17:15:37 kamil Exp $

DISTNAME=	logswan-1.05
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}

MAINTAINER=	fred@statdns.com
HOMEPAGE=	http://www.logswan.org/
COMMENT=	Fast Web log analyzer using probabilistic data structures
LICENSE=	modified-bsd

USE_CMAKE=	yes

CMAKE_ARGS+=	-DGEOIPDIR=${PREFIX}/share/GeoIP

.include "../../textproc/jansson/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
