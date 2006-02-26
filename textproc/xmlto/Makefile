# $NetBSD: Makefile,v 1.8 2006/02/26 12:50:03 rillig Exp $
#

DISTNAME=		xmlto-0.0.18
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		http://cyberelk.net/tim/data/xmlto/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://cyberelk.net/tim/xmlto/index.html
COMMENT=		Tool to help transform XML documents into other formats

DEPENDS+=		getopt-[0-9]*:../../misc/getopt
DEPENDS+=		bash-[0-9]*:../../shells/bash
DEPENDS+=		docbook-xsl>=1.67.0nb1:../../textproc/docbook-xsl
DEPENDS+=		libxml2>=2.6.2:../../textproc/libxml2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		SGML_CATALOG_FILES=${PREFIX:Q}/share/xml/catalog
CONFIGURE_ARGS+=	--with-getopt=${PREFIX:Q}/bin/getopt

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/xmlto/format/docbook
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/xmlto/format/fo
	@${SED} s,/bin/bash,${PREFIX:Q}/bin/bash, \
		${WRKSRC:Q}/xmlto  > ${WRKDIR:Q}/xmlto.new
	@${MV} ${WRKDIR:Q}/xmlto.new ${WRKSRC:Q}/xmlto

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
