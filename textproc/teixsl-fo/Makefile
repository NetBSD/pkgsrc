# $NetBSD: Makefile,v 1.9 2004/08/03 14:10:30 minskim Exp $

DISTNAME=	teixsl-fo
PKGNAME=	${DISTNAME}-3.1
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Stylesheets/P4/
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tei-c.org/Stylesheets/teixsl.html
COMMENT=	XSLT Stylesheets to convert TEI to XSL Formatting Objects

DEPENDS+=	teixsl-html-[0-9]*:../../textproc/teixsl-html

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME}
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_BUILDLINK3=	YES

XSLDIR=		${PREFIX}/share/xsl/tei/fo

XML_ENTRIES=	system "http://www.tei-c.org/Stylesheets/P4/tei.xsl" \
		${PREFIX}/share/xsl/tei/fo/tei.xsl

do-install:
	${INSTALL_DATA_DIR} ${XSLDIR}
	${INSTALL_DATA} ${WRKSRC}/fo/*.xsl ${XSLDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
