# $NetBSD: Makefile,v 1.9 2003/07/21 17:34:05 martti Exp $
#

PKGNAME=	sawfish-replibs-${SF_VERS}
PKGREVISION=	2

COMMENT=	Librep Lisp libraries for sawfish

do-build:
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} client.la

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/sawfish
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install-client-la

.include "../../wm/sawfish/Makefile.common"
