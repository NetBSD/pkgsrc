# $NetBSD: Makefile,v 1.7 2003/07/17 22:54:56 grant Exp $
#

DISTNAME=	xmlcatmgr-0.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlcatmgr/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://xmlcatmgr.sourceforge.net/
COMMENT=	XML catalog manager

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES

MAKEFILE=	Makefile.boot
MAKE_ENV+=	BT_PREFIX="${PREFIX}"
MAKE_ENV+=	BT_PROG_AWK="${AWK}"
MAKE_ENV+=	BT_PROG_SH="${SH}"
MAKE_ENV+=	BT_DIR_CATALOG="${PKG_SYSCONFDIR}/xml"
MAKE_ENV+=	BT_INSTALL_DIR="${INSTALL_DATA_DIR}"
MAKE_ENV+=	BT_INSTALL_BIN="${INSTALL_SCRIPT}"
MAKE_ENV+=	BT_INSTALL_DATA="${INSTALL_DATA}"

OWN_DIRS=	${PKG_SYSCONFDIR}/sgml ${PKG_SYSCONFDIR}/xml
EGDIR=		${PREFIX}/share/examples/xmlcatmgr
CONF_FILES=	${EGDIR}/catalog.etc.sgml ${PKG_SYSCONFDIR}/sgml/catalog
CONF_FILES+=	${EGDIR}/catalog.etc.xml ${PKG_SYSCONFDIR}/xml/catalog

post-build:
	@${ECHO} "Creating SGML catalogs..."
	@${WRKSRC}/bin/xmlcatmgr.sh -sc ${WRKDIR}/catalog.etc.sgml create
	@${WRKSRC}/bin/xmlcatmgr.sh -sc ${WRKDIR}/catalog.sgml create
	@${WRKSRC}/bin/xmlcatmgr.sh -sc ${WRKDIR}/catalog.etc.sgml add \
		CATALOG ${PREFIX}/share/sgml/catalog
	@${ECHO} "Creating XML catalogs..."
	@${WRKSRC}/bin/xmlcatmgr.sh -c ${WRKDIR}/catalog.etc.xml create
	@${WRKSRC}/bin/xmlcatmgr.sh -c ${WRKDIR}/catalog.xml create
	@${WRKSRC}/bin/xmlcatmgr.sh -c ${WRKDIR}/catalog.etc.xml add \
		nextCatalog ${PREFIX}/share/xml/catalog

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/sgml
	${INSTALL_DATA_DIR} ${PREFIX}/share/xml
	${INSTALL_DATA} ${WRKDIR}/catalog.etc.sgml ${EGDIR}/catalog.etc.sgml
	${INSTALL_DATA} ${WRKDIR}/catalog.etc.xml ${EGDIR}/catalog.etc.xml
	${INSTALL_DATA} ${WRKDIR}/catalog.sgml ${PREFIX}/share/sgml/catalog
	${INSTALL_DATA} ${WRKDIR}/catalog.xml ${PREFIX}/share/xml/catalog

.include "../../mk/bsd.pkg.mk"
