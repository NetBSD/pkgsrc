# $NetBSD: Makefile,v 1.1.1.1 2000/10/29 23:47:41 jlam Exp $
#

PKGNAME=	sawfish-replibs-${SF_VERS}

do-build:
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} client.la

do-install:
	${MKDIR} ${PREFIX}/libexec/rep/${MACHINE_GNU_PLATFORM}/sawfish
	cd ${WRKSRC}/src && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install-client-la

.include "../../x11/sawfish/Makefile.common"
