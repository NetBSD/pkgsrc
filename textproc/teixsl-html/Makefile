# $NetBSD: Makefile,v 1.7 2004/04/27 20:53:34 jmmv Exp $

DISTNAME=	teixsl-html
PKGNAME=	${DISTNAME}-3.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Stylesheets/P4/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tei-c.org/Stylesheets/teixsl.html
COMMENT=	XSLT Stylesheets to convert TEI to HTML

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME}
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_BUILDLINK3=	YES

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
