# $NetBSD: Makefile,v 1.3 2012/10/25 06:57:03 asau Exp $
#

DISTNAME=	tei-p5-schema-1.2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tei/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tei-c.org/
COMMENT=	TEI P5 schema files

USE_LANGUAGES=	# none
NO_BUILD=	yes

XML_CATALOGS=	${TEIXMLDIR}/schema/catalog.xml

TEIXMLDIR=	${PREFIX}/share/xml/tei

INSTALLATION_DIRS=	${TEIXMLDIR}

do-install:
	cd ${WRKSRC}/share/xml/tei && \
		${CP} -R schema ${DESTDIR}${TEIXMLDIR}

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
