# $NetBSD: Makefile,v 1.80 2022/02/04 11:28:49 hauke Exp $

DISTNAME=	lxml-4.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxml.de/
COMMENT=	Python binding for libxml2 and libxslt
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
TEST_DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.7:../../textproc/py-cssselect

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		nosunos
.if ${OPSYS} != "SunOS"
PLIST.nosunos=		yes
.endif

PYSETUPTESTARGS=	--run-tests

.include "../../devel/zlib/buildlink3.mk"

.include "../../lang/python/egg.mk"
# Needs to happen after the PYSITELIB substitution to prefix the line
PRINT_PLIST_AWK+=	{ gsub(/.*\/iso_schematron_skeleton_for_xslt1\.xsl$$/, "$${PLIST.nosunos}&"); }

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.9.12
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.34
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
# fix for UnicodeEncodeError: 'ascii' codec can't encode characters
TEST_ENV+=	LC_ALL=en_US.UTF-8
