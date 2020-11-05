# $NetBSD: Makefile,v 1.35 2020/11/05 09:09:16 ryoon Exp $

DISTNAME=	xmlto-0.0.28
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	https://releases.pagure.org/xmlto/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pagure.io/xmlto/
COMMENT=	Tool to help transform XML documents into other formats
LICENSE=	gnu-gpl-v2

DEPENDS+=		getopt-[0-9]*:../../misc/getopt
DEPENDS+=		docbook-xsl>=1.67.0nb1:../../textproc/docbook-xsl
DEPENDS+=		libxml2>=2.6.2:../../textproc/libxml2

USE_GCC_RUNTIME=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		mktemp
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		GETOPT=${PREFIX}/bin/getopt
CONFIGURE_ENV+=		BASH=${TOOLS_PATH.sh}
CONFIGURE_ENV+=		GCP=${TOOLS_PATH.cp}
CONFIGURE_ENV+=		TAIL=${TOOLS_PATH.tail}

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

## FIXME: the package should use XML catalog to access transformations from docbook-xsl package
SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-build
SUBST_MESSAGE.fix-paths=	Fixing location of XSLTs.
SUBST_FILES.fix-paths=		format/docbook/*
SUBST_SED.fix-paths=		-e 's,http://docbook.sourceforge.net/release/xsl/current/,file://${PREFIX}/share/xsl/docbook/,g'

MAKE_ENV+=		SGML_CATALOG_FILES=${PREFIX}/share/xml/catalog
REPLACE_BASH+=		xmlif/test/run-test
TEST_TARGET=		check

INSTALLATION_DIRS=	share/xmlto/format/docbook share/xmlto/format/fo

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
