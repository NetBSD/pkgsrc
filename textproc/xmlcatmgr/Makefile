# $NetBSD: Makefile,v 1.19 2004/04/22 13:11:58 jschauma Exp $
#

DISTNAME=	xmlcatmgr-2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmlcatmgr/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://xmlcatmgr.sourceforge.net/
COMMENT=	XML and SGML catalog manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

HAS_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	-p ${PREFIX}
CONFIGURE_ARGS+=	-c ${PKG_SYSCONFDIR}/xml/catalog
CONFIGURE_ARGS+=	-C ${PKG_SYSCONFDIR}/sgml/catalog
CONFIGURE_ENV+=		SED="${SED}"
CONFIGURE_ENV+=		INSTALL_DATA="${INSTALL_DATA}"
CONFIGURE_ENV+=		INSTALL_DIR="${INSTALL_DATA_DIR}"
CONFIGURE_ENV+=		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
CONFIGURE_SCRIPT=	${WRKSRC}/configure.sh

OWN_DIRS=	${PKG_SYSCONFDIR}/sgml ${PKG_SYSCONFDIR}/xml
EGDIR=		${PREFIX}/share/examples/xmlcatmgr
CONF_FILES=	${EGDIR}/catalog.etc.sgml ${PKG_SYSCONFDIR}/sgml/catalog
CONF_FILES+=	${EGDIR}/catalog.etc.xml ${PKG_SYSCONFDIR}/xml/catalog
MAKE_DIRS=	${PREFIX}/share/sgml ${PREFIX}/share/xml
SUPPORT_FILES=	${EGDIR}/catalog.share.sgml ${PREFIX}/share/sgml/catalog
SUPPORT_FILES+=	${EGDIR}/catalog.share.xml ${PREFIX}/share/xml/catalog

BUILD_DIRS=	${WRKSRC}/work
INSTALL_DIRS=	${WRKSRC}/work

.include "../../mk/bsd.prefs.mk"

.if defined(USE_MIPSPRO) && !empty(USE_MIPSPRO:M[yY][eE][sS])
CFLAGS+=	-c99
.endif

post-build:
	@${ECHO} "Creating SGML catalogs..."
	@${WRKSRC}/work/xmlcatmgr -sc ${WRKDIR}/catalog.etc.sgml create
	@${WRKSRC}/work/xmlcatmgr -sc ${WRKDIR}/catalog.sgml create
	@${WRKSRC}/work/xmlcatmgr -sc ${WRKDIR}/catalog.etc.sgml add \
		CATALOG ${PREFIX}/share/sgml/catalog
	@${ECHO} "Creating XML catalogs..."
	@${WRKSRC}/work/xmlcatmgr -c ${WRKDIR}/catalog.etc.xml create
	@${WRKSRC}/work/xmlcatmgr -c ${WRKDIR}/catalog.xml create
	@${WRKSRC}/work/xmlcatmgr -c ${WRKDIR}/catalog.etc.xml add \
		nextCatalog ${PREFIX}/share/xml/catalog

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/catalog.etc.sgml ${EGDIR}/catalog.etc.sgml
	${INSTALL_DATA} ${WRKDIR}/catalog.etc.xml ${EGDIR}/catalog.etc.xml
	${INSTALL_DATA} ${WRKDIR}/catalog.sgml ${EGDIR}/catalog.share.sgml
	${INSTALL_DATA} ${WRKDIR}/catalog.xml ${EGDIR}/catalog.share.xml

.include "../../mk/bsd.pkg.mk"
