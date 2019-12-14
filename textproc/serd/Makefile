# $NetBSD: Makefile,v 1.6 2019/12/14 17:31:12 nia Exp $

DISTNAME=	serd-0.30.2
CATEGORIES=	textproc
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/serd/
COMMENT=	Lightweight C library for RDF syntax
LICENSE=	isc

USE_LANGUAGES=	c99
USE_TOOLS+=	gsed pkg-config

PKGCONFIG_OVERRIDE+=	serd.pc.in

.include "options.mk"

BUILD_OPTIONS=	${BUILD_DEBUG} ${BUILD_DOC} ${BUILD_TESTS} ${BUILD_VALGRIND}

do-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${PYTHONBIN} ./waf configure \
			--destdir=${DESTDIR} --mandir=${PREFIX}/${PKGMANDIR} \
				${BUILD_OPTIONS}
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./waf build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} ./waf install

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
