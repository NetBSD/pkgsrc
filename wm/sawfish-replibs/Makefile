# $NetBSD: Makefile,v 1.7 2003/05/02 11:56:37 wiz Exp $
#

PKGNAME=	sawfish-replibs-${SF_VERS}
PKGREVISION=	1

COMMENT=	librep Lisp libraries for sawfish

do-build:
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} client.la

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/sawfish
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install-client-la

.include "../../wm/sawfish/Makefile.common"
