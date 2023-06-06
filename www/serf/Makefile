# $NetBSD: Makefile,v 1.42 2023/06/06 10:55:13 wiz Exp $

DISTNAME=	serf-1.3.10
CATEGORIES=	www
MASTER_SITES=	https://www.apache.org/dist/serf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://serf.apache.org/
COMMENT=	High-performance asynchronous HTTP client library
LICENSE=	apache-2.0

SCONS_ARGS+=		APR=${PREFIX}/bin/apr-1-config
SCONS_ARGS+=		APU=${PREFIX}/bin/apu-1-config
SCONS_ARGS+=		CC=${CC:Q}
SCONS_ARGS+=		CFLAGS=${CFLAGS:Q}
SCONS_ARGS+=		LDFLAGS=${LDFLAGS:Q}
SCONS_ARGS+=		LINKFLAGS=${LDFLAGS:Q}
SCONS_ARGS+=		OPENSSL=${PREFIX}/lib
SCONS_ARGS+=		--install-sandbox=${DESTDIR}

.include "options.mk"

CFLAGS.SunOS+=		-D__EXTENSIONS__

# Upstream distfile incorrectly has world-writable files.
post-extract:
	${CHMOD} -R go-w ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} PREFIX=${PREFIX} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} PREFIX=${PREFIX} ${SCONS_ARGS} install

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY?=	yes
.include "../../devel/scons/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
