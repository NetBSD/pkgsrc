# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 23:49:02 xtraeme Exp $

DISTNAME=	teixsl-html
PKGNAME=	${DISTNAME}-3.0
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Stylesheets/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.tei-c.org/Stylesheets/teixsl.html
COMMENT=	XSLT Stylesheets to convert TEI to HTML

NO_CONFIGURE=	YES
NO_BUILD=	YES

XSLDIR=		${PREFIX}/share/xsl/tei/html

XML_CATALOGS=	${XSLDIR}/catalog

do-install:
	${INSTALL_DATA_DIR} ${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.xsl ${XSLDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${XSLDIR}/catalog

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
