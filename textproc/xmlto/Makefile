# $NetBSD: Makefile,v 1.19 2011/04/22 13:44:52 obache Exp $

DISTNAME=	xmlto-0.0.23
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	# ftp(1) doesn't speak https: https://fedorahosted.org/releases/x/m/xmlto/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fedorahosted.org/xmlto/
COMMENT=	Tool to help transform XML documents into other formats
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
