# $NetBSD: Makefile,v 1.8 2005/04/28 23:32:43 jlam Exp $
#

DISTNAME=	pcal-4.7
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://membled.com/work/mirror/pcal/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kei@NetBSD.org
# pcal's home used to be http://www.geocities.com/SunsetStrip/Palms/5555/PS/
HOMEPAGE=	http://membled.com/work/mirror/pcal/
COMMENT=	PostScript calendar program

HTDOCS=		${PREFIX}/share/httpd/htdocs
CGIBINDIR=	${PREFIX}/libexec/cgi-bin
WWWSERVER=	${HOSTNAME_CMD:sh}

.include "../../mk/bsd.prefs.mk"	# for PAPERSIZE
.include <bsd.sys.mk>			# for CC and HOST_CC
MAKE_ENV+=	PAPERSIZE="${PAPERSIZE}"
MAKE_ENV+=	CC="${CC}" HOST_CC="${HOST_CC}"

BUILD_TARGET=	pcal

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
	${INSTALL_SCRIPT_DIR} ${CGIBINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/pcal.cgi ${CGIBINDIR}
	${INSTALL_MAN} ${WRKSRC}/pcal.man ${PREFIX}/man/man1/pcal.1
	${INSTALL_DATA} ${WRKSRC}/ReadMe ${PREFIX}/share/doc/ReadMe.pcal
	${INSTALL_DATA_DIR} ${HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/pcal.html ${HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/pcalw.html ${HTDOCS}

.include "../../mk/bsd.pkg.mk"
