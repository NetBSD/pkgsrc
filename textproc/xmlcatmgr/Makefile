# $NetBSD: Makefile,v 1.2 2003/01/11 21:08:42 jmmv Exp $
#

DISTNAME=	xmlcatmgr-0.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlcatmgr/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://www.sourceforge.net/projects/xmlcatmgr/
COMMENT=	XML catalog manager

USE_BUILDLINK2=	YES

MAKEFILE=	Makefile.boot
MAKE_ENV+=	BT_PREFIX="${PREFIX}"
MAKE_ENV+=	BT_PROG_AWK="${AWK}"
MAKE_ENV+=	BT_PROG_SH="${SH}"
MAKE_ENV+=	BT_DIR_CATALOG="${PKG_SYSCONFDIR}"

EGDIR=		${PREFIX}/share/examples/xmlcatmgr
CONF_FILES=	${EGDIR}/catalog.global ${PKG_SYSCONFDIR}/catalog

post-build:
	${WRKSRC}/bin/xmlcatmgr.sh -c ${WRKDIR}/catalog.global create
	${WRKSRC}/bin/xmlcatmgr.sh -c ${WRKDIR}/catalog.sgml create
	${WRKSRC}/bin/xmlcatmgr.sh -c ${WRKDIR}/catalog.xml create
	${WRKSRC}/bin/xmlcatmgr.sh -c ${WRKDIR}/catalog.global add \
		CATALOG ${PREFIX}/share/sgml/catalog
	${WRKSRC}/bin/xmlcatmgr.sh -c ${WRKDIR}/catalog.global add \
		CATALOG ${PREFIX}/share/xml/catalog

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/sgml
	${INSTALL_DATA_DIR} ${PREFIX}/share/xml
	${INSTALL_DATA} ${WRKDIR}/catalog.global ${EGDIR}/catalog.global
	${INSTALL_DATA} ${WRKDIR}/catalog.sgml ${PREFIX}/share/sgml/catalog
	${INSTALL_DATA} ${WRKDIR}/catalog.xml ${PREFIX}/share/xml/catalog

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
