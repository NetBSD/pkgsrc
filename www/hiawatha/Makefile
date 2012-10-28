# $NetBSD: Makefile,v 1.29 2012/10/28 06:30:17 asau Exp $
#

DISTNAME=	hiawatha
PKGNAME=	hiawatha-0.1
PKGREVISION=	5
CATEGORIES=	textproc www
MASTER_SITES=	${HOMEPAGE} ${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		sitedrivenby.gif

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pault.com/pault/downloads/
COMMENT=	Barebones HTTP server with XML and XSLT support (and more)

DEPENDS+=	saxon-[0-9]*:../../textproc/saxon

NO_CONFIGURE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_TOOLS+=	pax

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

RCD_SCRIPTS=	hiawatha

EGDIR=		${PREFIX}/share/examples/hiawatha
CONF_FILES=	${EGDIR}/hiawatha.cfg ${PKG_SYSCONFDIR}/hiawatha.cfg

OWN_DIRS=	/var/spool/hiawatha

post-extract:
	${SED}  -e "s,@PREFIX@,${PREFIX},g" \
		-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g" \
		< ${FILESDIR}/hiawatha.cfg > ${WRKDIR}/hiawatha.cfg
	${CHMOD} -R go-w ${WRKSRC}

INSTALLATION_DIRS=	lib/java/hiawatha ${EGDIR}/WEBROOT/images

do-install:
	${INSTALL_DATA} ${WRKSRC}/hiawatha.jar ${DESTDIR}${PREFIX}/lib/java/hiawatha
	${INSTALL_DATA} ${WRKSRC}/xsls.jar ${DESTDIR}${PREFIX}/lib/java/hiawatha
	${INSTALL_DATA} ${WRKSRC}/simple.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/SeeAlso/pault_com.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/hiawatha.cfg ${DESTDIR}${EGDIR}
	cd ${WRKSRC} && chmod -R go-w WEBROOT
	cd ${WRKSRC} && pax -s '/^WEBROOT/pault.com/' -rw WEBROOT ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/index.xml ${DESTDIR}${EGDIR}/WEBROOT
	${INSTALL_DATA} ${FILESDIR}/index.xsl ${DESTDIR}${EGDIR}/WEBROOT
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${DESTDIR}${EGDIR}/WEBROOT/images

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
