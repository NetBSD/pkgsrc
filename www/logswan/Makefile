# $NetBSD: Makefile,v 1.31 2026/10/24 19:02:21 drixter Exp $

DISTNAME=	logswan-2.1.17
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://www.logswan.org/
COMMENT=	Fast Web log analyzer using probabilistic data structures
LICENSE=	2-clause-bsd

CMAKE_CONFIGURE_ARGS+=	-DGEOIP2DIR=${PREFIX}/share/dbip
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

TEST_TARGET=	test

.include "../../devel/cmake/build.mk"

.include "../../textproc/jansson/buildlink3.mk"
.include "../../geography/libmaxminddb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
