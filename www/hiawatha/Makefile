# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:52 jlam Exp $
#

DISTNAME=	hiawatha
PKGNAME=	hiawatha-0.1
CATEGORIES=	textproc www
MASTER_SITES=	${HOMEPAGE} ${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		sitedrivenby.gif

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.pault.com/pault/downloads/
COMMENT=	Barebones HTTP server with XML and XSLT support (and more)

DEPENDS+=	saxon-[0-9]*:../../textproc/saxon

NO_PATCH=
NO_CONFIGURE=
NO_BUILD=
WRKSRC=		${WRKDIR}

USE_JAVA=	yes
DIST_SUBDIR=	${PKGNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=	unzip -aq ${DOWNLOADED_DISTFILE}

post-extract:
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/hiawatha.sh \
		> ${WRKDIR}/hiawatha.sh
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/hiawatha.cfg \
		> ${WRKDIR}/hiawatha.cfg

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/hiawatha
	${INSTALL_DATA} ${WRKSRC}/hiawatha.jar ${PREFIX}/lib/java/hiawatha
	${INSTALL_DATA} ${WRKSRC}/xsls.jar ${PREFIX}/lib/java/hiawatha
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hiawatha
	${INSTALL_DATA} ${WRKSRC}/simple.cfg \
		${PREFIX}/share/examples/hiawatha
	${INSTALL_DATA} ${WRKSRC}/SeeAlso/pault_com.cfg \
		${PREFIX}/share/examples/hiawatha
	if [ ! -f ${PREFIX}/etc/hiawatha.cfg ]; \
	then \
		${INSTALL_DATA} ${WRKDIR}/hiawatha.cfg ${PREFIX}/etc \
	; fi
	${INSTALL_DATA} ${WRKDIR}/hiawatha.cfg ${PREFIX}/share/examples/hiawatha
	(cd ${WRKSRC} && ${PAX} -s '/^WEBROOT/pault.com/' -rw WEBROOT ${PREFIX}/share/examples/hiawatha)
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hiawatha/WEBROOT
	${INSTALL_DATA} ${FILESDIR}/index.xml ${PREFIX}/share/examples/hiawatha/WEBROOT
	${INSTALL_DATA} ${FILESDIR}/index.xsl ${PREFIX}/share/examples/hiawatha/WEBROOT
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hiawatha/WEBROOT/images
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/examples/hiawatha/WEBROOT/images
	${INSTALL_SCRIPT} ${WRKDIR}/hiawatha.sh ${PREFIX}/etc/rc.d/hiawatha

.include "../../mk/bsd.pkg.mk"
