# $NetBSD: Makefile,v 1.12.2.1 2002/06/23 19:07:11 jlam Exp $

DISTNAME=	xephem-3.5.2
CATEGORIES=	x11
MASTER_SITES=	http://www.clearskyinstitute.com/xephem/ \
		ftp://iphcip1.physik.uni-mainz.de/pub/xephem/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.clearskyinstitute.com/xephem/
COMMENT=	Interactive astronomical ephemeris program

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem
LIBSRC1=		${WRKDIR}/${DISTNAME}/libastro
LIBSRC2=	${WRKDIR}/${DISTNAME}/libip
USE_PERL5=	yes

LICENSE=	no-commercial-use

.if (${MACHINE_ARCH} == "arm32")
. include "../../lang/gcc/Makefile.gcc"
MAKE_FLAGS+=	CC=${CC}
.endif

USE_IMAKE=	yes

pre-build:
	(cd ${LIBSRC1}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS})
	(cd ${LIBSRC2}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS})

PERL_SCRIPTS= astorb2edb.pl mpcorb2edb.pl

post-install:
	${SED} s,@PREFIX@,${PREFIX}, ${FILESDIR}/XEphem.ad > ${WRKDIR}/XEphem
	${INSTALL_DATA} ${WRKDIR}/XEphem ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA_DIR} ${PREFIX}/share/xephem/tools
	(cd ${WRKSRC}; ${CP} -R auxil catalogs fifos fits \
	 ${PREFIX}/share/xephem)
	(cd ${WRKSRC}/tools; for file in ${PERL_SCRIPTS}; do \
		${SED} 1s,@LOCALBASE@,${LOCALBASE}, $$file \
			> ${WRKDIR}/$$file; \
		${INSTALL_SCRIPT} ${WRKDIR}/$$file \
			${PREFIX}/share/xephem/tools; \
	done)
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/xephem

.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
