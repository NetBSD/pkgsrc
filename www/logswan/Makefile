# $NetBSD: Makefile,v 1.4 2016/01/11 07:11:20 kamil Exp $

DISTNAME=	logswan-1.04
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logswan.org
COMMENT=	Fast Web log analyzer using probabilistic data structures
LICENSE=	modified-bsd

USE_CMAKE=	yes

CMAKE_ARGS+=	-DGEOIPDIR=${PREFIX}/share/GeoIP

.include "../../textproc/jansson/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
