# $NetBSD: Makefile,v 1.29 2014/05/04 06:18:38 adam Exp $

DISTNAME=	serf-1.3.5
CATEGORIES=	www
MASTER_SITES=	http://serf.googlecode.com/svn/src_releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/serf/
COMMENT=	High-performance asynchronous HTTP client library
LICENSE=	apache-2.0

BUILD_DEPENDS+=		scons>=2.3.0:../../devel/scons

SCONS_ARGS+=		APR=${PREFIX}/bin/apr-1-config
SCONS_ARGS+=		APU=${PREFIX}/bin/apu-1-config
SCONS_ARGS+=		CC=${CC:Q}
SCONS_ARGS+=		CFLAGS=${CFLAGS:Q}
SCONS_ARGS+=		LDFLAGS=${LDFLAGS:Q}
SCONS_ARGS+=		OPENSSL=${PREFIX}/lib
SCONS_ARGS+=		GSSAPI=${KRB5_CONFIG:Q}
SCONS_ARGS+=		--install-sandbox=${DESTDIR}

CFLAGS.SunOS+=		-D__EXTENSIONS__

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons PREFIX=${PREFIX} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons PREFIX=${PREFIX} ${SCONS_ARGS} install

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
