# $NetBSD: Makefile,v 1.11 2004/01/03 18:49:54 reed Exp $
#

PKGNAME=	sawfish-replibs-${SF_VERS}
PKGREVISION=	4

COMMENT=	Librep Lisp libraries for sawfish

do-build:
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} client.la

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/sawfish
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install-client-la

.include "../../wm/sawfish/Makefile.common"
