# $NetBSD: Makefile,v 1.93 2023/11/08 23:00:56 wiz Exp $

DISTNAME=	lxml-4.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxml.de/
COMMENT=	Python binding for libxml2 and libxslt
LICENSE=	modified-bsd

USE_CC_FEATURES=	c99

# Path too long for nbtar (pax-as-tar)?
# See pkg/56688: nbtar (archivers/pax) silently drops files
EXTRACT_USING=	gtar

TEST_DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.7:../../textproc/py-cssselect

PYSETUPTESTARGS=	--run-tests

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.9.12
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.34
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
# fix for UnicodeEncodeError: 'ascii' codec can't encode characters
TEST_ENV+=	LC_ALL=en_US.UTF-8
