# $NetBSD: Makefile,v 1.1.1.1 2000/12/21 06:20:53 kei Exp $
#

DISTNAME=	pcal_4_7_tar_Z
PKGNAME=	pcal-4.7
CATEGORIES=	time
MASTER_SITES=	http://www.geocities.com/SunsetStrip/Palms/5555/PS/
EXTRACT_SUFX=	.txt

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.geocities.com/SunsetStrip/Palms/5555/PS/index.html

UUDECODE?=	uudecode -p
EXTRACT_CMD=	${CAT} ${DOWNLOADED_DISTFILE} | ${UUDECODE} | ${PAX} -rz

WRKSRC=		${WRKDIR}/pcal.4.7

HTDOCS=		${PREFIX}/share/httpd/htdocs
WWWSERVER!=	hostname

.include "../../mk/bsd.prefs.mk"	# for PAPERSIZE
.include <bsd.sys.mk>			# for CC and HOST_CC
MAKE_ENV+=	PAPERSIZE="${PAPERSIZE}"
MAKE_ENV+=	CC="${CC}" HOST_CC="${HOST_CC}"

ALL_TARGET=	pcal

pre-install:
		${MV} ${WRKSRC}/pcal.cgi ${WRKSRC}/pcal.cgi.tmp
		${SED} -e 's|@@PREFIX@@|${PREFIX}|' \
			< ${WRKSRC}/pcal.cgi.tmp > ${WRKSRC}/pcal.cgi
		${MV} ${WRKSRC}/pcal.html ${WRKSRC}/pcal.html.tmp
		${SED} -e 's|@@WWWSERVER@@|${WWWSERVER}|' \
			< ${WRKSRC}/pcal.html.tmp > ${WRKSRC}/pcal.html
		${MV} ${WRKSRC}/pcalw.html ${WRKSRC}/pcalw.html.tmp
		${SED} -e 's|@@WWWSERVER@@|${WWWSERVER}|' \
			< ${WRKSRC}/pcalw.html.tmp > ${WRKSRC}/pcalw.html

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/pcal ${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC}/pcal.cgi ${PREFIX}/libexec/cgi-bin
		${INSTALL_MAN} ${WRKSRC}/pcal.man ${PREFIX}/man/man1/pcal.1
		${INSTALL_DATA} ${WRKSRC}/ReadMe ${PREFIX}/share/doc/ReadMe.pcal
		${INSTALL_DATA_DIR} ${HTDOCS}
		${INSTALL_DATA} ${WRKSRC}/pcal.html ${HTDOCS}
		${INSTALL_DATA} ${WRKSRC}/pcalw.html ${HTDOCS}

.include "../../mk/bsd.pkg.mk"
