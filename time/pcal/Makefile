# $NetBSD: Makefile,v 1.20 2020/04/08 06:14:46 riastradh Exp $
#

DISTNAME=	pcal-4.11.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pcal/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pcal.sourceforge.net/
COMMENT=	PostScript calendar program

HTDOCS=		${PREFIX}/share/httpd/htdocs
CGIBINDIR=	${PREFIX}/libexec/cgi-bin
WWWSERVER=	${HOSTNAME_CMD:sh}

USE_TOOLS+=	gmake

MAKE_ENV+=	CC=${CC:Q}

BUILD_TARGET=	exec/pcal

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/pcal ${HTDOCS} ${CGIBINDIR}

pre-install:
	${MV} ${WRKSRC}/html/pcal.cgi ${WRKSRC}/html/pcal.cgi.tmp
	${SED} -e 's|@@PREFIX@@|${PREFIX}|' \
		< ${WRKSRC}/html/pcal.cgi.tmp > ${WRKSRC}/html/pcal.cgi
	${MV} ${WRKSRC}/html/pcal.html ${WRKSRC}/html/pcal.html.tmp
	${SED} -e 's|@@WWWSERVER@@|${WWWSERVER}|' \
		< ${WRKSRC}/html/pcal.html.tmp > ${WRKSRC}/html/pcal.html
	${MV} ${WRKSRC}/html/pcalw.html ${WRKSRC}/html/pcalw.html.tmp
	${SED} -e 's|@@WWWSERVER@@|${WWWSERVER}|' \
		< ${WRKSRC}/html/pcalw.html.tmp > ${WRKSRC}/html/pcalw.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/exec/pcal ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/html/pcal.cgi ${DESTDIR}${CGIBINDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/pcal.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pcal.1
	${INSTALL_DATA} ${WRKSRC}/doc/ReadMe.txt ${DESTDIR}${PREFIX}/share/doc/pcal/README
	${INSTALL_DATA} ${WRKSRC}/html/pcal.html ${DESTDIR}${HTDOCS}
	${INSTALL_DATA} ${WRKSRC}/html/pcalw.html ${DESTDIR}${HTDOCS}

.include "../../mk/bsd.pkg.mk"
