# $NetBSD: Makefile,v 1.3 2001/02/25 04:18:21 hubertf Exp $
#

PKGNAME=	sawfish-replibs-${SF_VERS}

COMMENT=	librep Lisp libraries for sawfish

do-build:
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} client.la

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/sawfish
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install-client-la

.include "../../wm/sawfish/Makefile.common"
