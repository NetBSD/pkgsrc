# $NetBSD: Makefile,v 1.2 2001/02/17 17:21:45 wiz Exp $
#

PKGNAME=	sawfish-replibs-${SF_VERS}

COMMENT=	librep Lisp libraries for sawfish

do-build:
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} client.la

do-install:
	${MKDIR} ${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/sawfish
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install-client-la

.include "../../wm/sawfish/Makefile.common"
