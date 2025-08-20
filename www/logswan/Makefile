# $NetBSD: Makefile,v 1.30 2025/08/20 11:35:14 wiz Exp $

DISTNAME=	logswan-2.1.14
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
