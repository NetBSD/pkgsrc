# $NetBSD: Makefile,v 1.13 2006/01/24 07:32:40 wiz Exp $
#

PKGNAME=	sawfish-replibs-${SF_VERS}
PKGREVISION=	6

COMMENT=	Librep Lisp libraries for sawfish

do-build:
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} client.la

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/sawfish
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install-client-la

.include "../../wm/sawfish/Makefile.common"
