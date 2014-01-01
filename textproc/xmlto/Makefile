# $NetBSD: Makefile,v 1.23 2014/01/01 11:52:36 wiz Exp $

DISTNAME=	xmlto-0.0.25
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://fedorahosted.org/releases/x/m/xmlto/
EXTRACT_SUFX=	.tar.bz2
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fedorahosted.org/xmlto/
COMMENT=	Tool to help transform XML documents into other formats
LICENSE=	gnu-gpl-v2

DEPENDS+=		getopt-[0-9]*:../../misc/getopt
DEPENDS+=		docbook-xsl>=1.67.0nb1:../../textproc/docbook-xsl
DEPENDS+=		libxml2>=2.6.2:../../textproc/libxml2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash:run mktemp
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		GETOPT=${PREFIX}/bin/getopt
CONFIGURE_ENV+=		BASH=${TOOLS_PATH.bash}
CONFIGURE_ENV+=		GCP=${TOOLS_PATH.cp}
CONFIGURE_ENV+=		TAIL=${TOOLS_PATH.tail}

MAKE_ENV+=		SGML_CATALOG_FILES=${PREFIX}/share/xml/catalog
REPLACE_BASH+=		xmlif/test/run-test
TEST_TARGET=		check

INSTALLATION_DIRS=	share/xmlto/format/docbook share/xmlto/format/fo

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
