# $NetBSD: Makefile,v 1.38 2006/05/10 16:45:35 gdt Exp $

DISTNAME=	xephem-3.7.1
CATEGORIES=	x11
MASTER_SITES=	http://www.clearskyinstitute.com/xephem/ \
		ftp://iphcip1.physik.uni-mainz.de/pub/xephem/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.clearskyinstitute.com/xephem/
COMMENT=	Interactive astronomical ephemeris program

LICENSE=		xephem-license
RESTRICTED=		No permission to distribute distfile or binary package.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/${DISTNAME}/GUI/xephem
USE_TOOLS+=	gmake perl:run

BUILD_ENV+=	X11_LDFLAGS=${X11_LDFLAGS:Q}

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	2.95.3
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xephem ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xephem.man ${PREFIX}/${PKGMANDIR}/man1/xephem.1
	${SED} s,@PREFIX@,${PREFIX}, ${FILESDIR}/XEphem.ad > ${WRKDIR}/XEphem
	${INSTALL_DATA} ${WRKDIR}/XEphem ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA_DIR} ${PREFIX}/share/xephem/tools
	cd ${WRKSRC}; ${CP} -R auxil catalogs fifos fits gallery help lo \
		${PREFIX}/share/xephem
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/xephem

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
