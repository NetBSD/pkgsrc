# $NetBSD: Makefile,v 1.10 2006/07/22 13:11:28 rillig Exp $
#

DISTNAME=		xmlto-0.0.18
PKGREVISION=		4
CATEGORIES=		textproc
MASTER_SITES=		http://cyberelk.net/tim/data/xmlto/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cyberelk.net/tim/xmlto/index.html
COMMENT=		Tool to help transform XML documents into other formats

DEPENDS+=		getopt-[0-9]*:../../misc/getopt
DEPENDS+=		docbook-xsl>=1.67.0nb1:../../textproc/docbook-xsl
DEPENDS+=		libxml2>=2.6.2:../../textproc/libxml2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		SGML_CATALOG_FILES=${PREFIX:Q}/share/xml/catalog
CONFIGURE_ARGS+=	--with-getopt=${PREFIX:Q}/bin/getopt

REPLACE_BASH+=		xmlto.in
USE_TOOLS+=		bash:run

INSTALLATION_DIRS=	share/xmlto/format/docbook share/xmlto/format/fo

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
