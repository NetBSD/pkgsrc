# $NetBSD: Makefile,v 1.14 2007/01/07 09:14:14 rillig Exp $
#

DISTNAME=	pcal-4.7
PKGREVISION=	2
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcal/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://pcal.sourceforge.net/
COMMENT=	PostScript calendar program

HTDOCS=		${PREFIX}/share/httpd/htdocs
CGIBINDIR=	${PREFIX}/libexec/cgi-bin
WWWSERVER=	${HOSTNAME_CMD:sh}

.include "../../mk/bsd.prefs.mk"	# for PAPERSIZE
MAKE_ENV+=	PAPERSIZE=${PAPERSIZE:Q}
MAKE_ENV+=	CC=${CC:Q} HOST_CC=${CC:Q}

BUILD_TARGET=	pcal

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/pcal ${HTDOCS}

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
	${INSTALL_MAN} ${WRKSRC}/pcal.man ${PREFIX}/${PKGMANDIR}/man1/pcal.1
	${INSTALL_DATA} ${WRKSRC}/ReadMe ${PREFIX}/share/doc/pcal/ReadMe
	${INSTALL_DATA} ${WRKSRC}/pcal.html ${HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/pcalw.html ${HTDOCS}

.include "../../mk/bsd.pkg.mk"
