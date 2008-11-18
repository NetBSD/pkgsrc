# $NetBSD: Makefile,v 1.16 2008/11/18 15:20:54 wiz Exp $
#

DISTNAME=		xmlto-0.0.21
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		# ftp(1) doesn't speak https: https://fedorahosted.org/xmlto/browser
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fedorahosted.org/xmlto/
COMMENT=		Tool to help transform XML documents into other formats

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		getopt-[0-9]*:../../misc/getopt
DEPENDS+=		docbook-xsl>=1.67.0nb1:../../textproc/docbook-xsl
DEPENDS+=		libxml2>=2.6.2:../../textproc/libxml2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		SGML_CATALOG_FILES=${PREFIX}/share/xml/catalog
CONFIGURE_ARGS+=	--with-getopt=${PREFIX}/bin/getopt
CONFIGURE_ARGS+=	--with-bash=${TOOLS_PATH.bash}

REPLACE_BASH+=		xmlif/test/run-test
USE_TOOLS+=		bash:run mktemp
TEST_TARGET=		check

INSTALLATION_DIRS=	share/xmlto/format/docbook share/xmlto/format/fo

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
