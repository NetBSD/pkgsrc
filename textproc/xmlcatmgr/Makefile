# $NetBSD: Makefile,v 1.12 2003/12/16 22:45:33 jmmv Exp $
#

DISTNAME=	xmlcatmgr-1.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlcatmgr/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://xmlcatmgr.sourceforge.net/
COMMENT=	XML (and SGML) catalog manager

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS=	awk

MAKEFILE=	Makefile.boot
MAKE_ENV+=	BT_PREFIX="${PREFIX}"
MAKE_ENV+=	BT_PROG_AWK="${AWK}"
MAKE_ENV+=	BT_PROG_GREP="${GREP}"
MAKE_ENV+=	BT_PROG_SH="${SH}"
MAKE_ENV+=	BT_DIR_CATALOG="${PKG_SYSCONFDIR}/xml"
MAKE_ENV+=	BT_INSTALL_DIR="${INSTALL_DATA_DIR}"
MAKE_ENV+=	BT_INSTALL_BIN="${INSTALL_SCRIPT}"
MAKE_ENV+=	BT_INSTALL_DATA="${INSTALL_DATA}"

OWN_DIRS=	${PKG_SYSCONFDIR}/sgml ${PKG_SYSCONFDIR}/xml
EGDIR=		${PREFIX}/share/examples/xmlcatmgr
CONF_FILES=	${EGDIR}/catalog.etc.sgml ${PKG_SYSCONFDIR}/sgml/catalog
CONF_FILES+=	${EGDIR}/catalog.etc.xml ${PKG_SYSCONFDIR}/xml/catalog
MAKE_DIRS=	${PREFIX}/share/sgml ${PREFIX}/share/xml
SUPPORT_FILES=	${EGDIR}/catalog.share.sgml ${PREFIX}/share/sgml/catalog
SUPPORT_FILES+=	${EGDIR}/catalog.share.xml ${PREFIX}/share/xml/catalog

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
	${INSTALL_DATA} ${WRKDIR}/catalog.etc.sgml ${EGDIR}/catalog.etc.sgml
	${INSTALL_DATA} ${WRKDIR}/catalog.etc.xml ${EGDIR}/catalog.etc.xml
	${INSTALL_DATA} ${WRKDIR}/catalog.sgml ${EGDIR}/catalog.share.sgml
	${INSTALL_DATA} ${WRKDIR}/catalog.xml ${EGDIR}/catalog.share.xml

.include "../../mk/bsd.pkg.mk"
