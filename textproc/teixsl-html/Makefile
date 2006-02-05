# $NetBSD: Makefile,v 1.13 2006/02/05 23:11:08 joerg Exp $

DISTNAME=	teixsl-html
PKGNAME=	${DISTNAME}-3.3
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Stylesheets/P4/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tei-c.org/Stylesheets/teixsl.html
COMMENT=	XSLT Stylesheets to convert TEI to HTML

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}
NO_CONFIGURE=	YES
NO_BUILD=	YES

TEIDIR=		${PREFIX}/share/xsl/tei

XML_ENTRIES=	system "http://www.tei-c.org/Stylesheets/P4/teihtml.xsl" \
		${PREFIX}/share/xsl/tei/html/tei.xsl

do-install:
	${INSTALL_DATA_DIR} ${TEIDIR}/common
	${INSTALL_DATA} ${WRKSRC}/common/*.xsl ${TEIDIR}/common
	${INSTALL_DATA_DIR} ${TEIDIR}/html
	${INSTALL_DATA} ${WRKSRC}/html/*.xsl ${TEIDIR}/html

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
