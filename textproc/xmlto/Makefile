# $NetBSD: Makefile,v 1.3 2005/01/03 13:36:36 wiz Exp $
#

DISTNAME=		xmlto-0.0.18
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

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		SGML_CATALOG_FILES=${PREFIX}/share/xml/catalog
CONFIGURE_ARGS+=	--with-getopt=${PREFIX}/bin/getopt

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xmlto/format/docbook
	${INSTALL_DATA_DIR} ${PREFIX}/share/xmlto/format/fo

.include "../../mk/bsd.pkg.mk"
