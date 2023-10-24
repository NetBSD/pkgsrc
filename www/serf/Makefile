# $NetBSD: Makefile,v 1.44 2023/10/24 22:11:33 wiz Exp $

DISTNAME=	serf-1.3.10
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://www.apache.org/dist/serf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://serf.apache.org/
COMMENT=	High-performance asynchronous HTTP client library
LICENSE=	apache-2.0

SCONS_BUILD_ARGS+=	APR=${PREFIX}/bin/apr-1-config
SCONS_BUILD_ARGS+=	APU=${PREFIX}/bin/apu-1-config
SCONS_BUILD_ARGS+=	CC=${CC:Q}
SCONS_BUILD_ARGS+=	CFLAGS=${CFLAGS:Q}
SCONS_BUILD_ARGS+=	LDFLAGS=${LDFLAGS:Q}
SCONS_BUILD_ARGS+=	LINKFLAGS=${LDFLAGS:Q}
SCONS_BUILD_ARGS+=	OPENSSL=${PREFIX}/lib
SCONS_INSTALL_ARGS+=	--install-sandbox=${DESTDIR}

.include "options.mk"

CFLAGS.SunOS+=		-D__EXTENSIONS__

# Upstream distfile incorrectly has world-writable files.
#post-extract:
#	${CHMOD} -R go-w ${WRKSRC}

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/scons4/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
