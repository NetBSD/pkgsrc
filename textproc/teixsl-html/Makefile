# $NetBSD: Makefile,v 1.4 2004/02/10 04:38:02 minskim Exp $

DISTNAME=	teixsl-html
PKGNAME=	${DISTNAME}-3.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Stylesheets/P4/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tei-c.org/Stylesheets/teixsl.html
COMMENT=	XSLT Stylesheets to convert TEI to HTML

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES
NO_BUILD=	YES

TEIDIR=		${PREFIX}/share/xsl/tei

XML_CATALOGS=	${TEIDIR}/html/catalog

do-install:
	${INSTALL_DATA_DIR} ${TEIDIR}/common
	${INSTALL_DATA} ${WRKSRC}/common/*.xsl ${TEIDIR}/common
	${INSTALL_DATA_DIR} ${TEIDIR}/html
	${INSTALL_DATA} ${WRKSRC}/html/*.xsl ${TEIDIR}/html
	${INSTALL_DATA} ${FILESDIR}/catalog ${TEIDIR}/html/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
