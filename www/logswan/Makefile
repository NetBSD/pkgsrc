# $NetBSD: Makefile,v 1.7 2016/12/18 18:49:39 maya Exp $

DISTNAME=	logswan-1.06
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logswan.org/
COMMENT=	Fast Web log analyzer using probabilistic data structures
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

CFLAGS+=	-D_XOPEN_SOURCE=600

CMAKE_ARGS+=	-DGEOIPDIR=${PREFIX}/share/GeoIP

.include "../../textproc/jansson/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
