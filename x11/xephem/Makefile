# $NetBSD: Makefile,v 1.26 2004/04/25 02:49:21 xtraeme Exp $

DISTNAME=	xephem-3.5.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.clearskyinstitute.com/xephem/ \
		ftp://iphcip1.physik.uni-mainz.de/pub/xephem/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.clearskyinstitute.com/xephem/
COMMENT=	Interactive astronomical ephemeris program

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem
USE_BUILDLINK3=	yes
USE_IMAKE=	yes
PERL_SCRIPTS=	astorb2edb.pl mpcorb2edb.pl

LIBSRC1=	${WRKDIR}/${DISTNAME}/libastro
LIBSRC2=	${WRKDIR}/${DISTNAME}/libip
ALL_TARGET=	# empty
BUILD_DIRS=	${LIBSRC1} ${LIBSRC2} ${WRKSRC}
INSTALL_DIRS=	${WRKSRC}

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	2.95.3
.endif

post-install:
	${SED} s,@PREFIX@,${PREFIX}, ${FILESDIR}/XEphem.ad > ${WRKDIR}/XEphem
	${INSTALL_DATA} ${WRKDIR}/XEphem ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA_DIR} ${PREFIX}/share/xephem/tools
	cd ${WRKSRC}; ${CP} -R auxil catalogs fifos fits		\
		${PREFIX}/share/xephem
	for file in ${PERL_SCRIPTS}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/tools/$${file}		\
			${PREFIX}/share/xephem/tools;			\
	done
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/xephem

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
