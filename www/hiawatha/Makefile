# $NetBSD: Makefile,v 1.17 2005/09/28 12:23:55 rillig Exp $
#

DISTNAME=	hiawatha
PKGNAME=	hiawatha-0.1
PKGREVISION=	2
CATEGORIES=	textproc www
MASTER_SITES=	${HOMEPAGE} ${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		sitedrivenby.gif

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.pault.com/pault/downloads/
COMMENT=	Barebones HTTP server with XML and XSLT support (and more)

DEPENDS+=	saxon-[0-9]*:../../textproc/saxon

NO_CONFIGURE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_PKGINSTALL=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=	unzip -aq ${DOWNLOADED_DISTFILE}

RCD_SCRIPTS=	hiawatha

EGDIR=		${PREFIX}/share/examples/hiawatha
CONF_FILES=	${EGDIR}/hiawatha.cfg ${PKG_SYSCONFDIR}/hiawatha.cfg

OWN_DIRS=	/var/spool/hiawatha

post-extract:
	${SED}  -e "s,@PREFIX@,${PREFIX},g" \
		-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g" \
		< ${FILESDIR}/hiawatha.cfg > ${WRKDIR}/hiawatha.cfg

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/hiawatha
	${INSTALL_DATA} ${WRKSRC}/hiawatha.jar ${PREFIX}/lib/java/hiawatha
	${INSTALL_DATA} ${WRKSRC}/xsls.jar ${PREFIX}/lib/java/hiawatha
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/simple.cfg ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/SeeAlso/pault_com.cfg ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/hiawatha.cfg ${EGDIR}
	cd ${WRKSRC} && ${PAX} -s '/^WEBROOT/pault.com/' -rw WEBROOT ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/WEBROOT
	${INSTALL_DATA} ${FILESDIR}/index.xml ${EGDIR}/WEBROOT
	${INSTALL_DATA} ${FILESDIR}/index.xsl ${EGDIR}/WEBROOT
	${INSTALL_DATA_DIR} ${EGDIR}/WEBROOT/images
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${EGDIR}/WEBROOT/images

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
