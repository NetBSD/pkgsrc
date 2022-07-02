# $NetBSD: Makefile,v 1.86 2022/07/02 07:55:31 adam Exp $

DISTNAME=	lxml-4.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxml.de/
COMMENT=	Python binding for libxml2 and libxslt
LICENSE=	modified-bsd

# Path too long for nbtar (pax-as-tar)?
# See pkg/56688: nbtar (archivers/pax) silently drops files
EXTRACT_USING=	gtar

TEST_DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
TEST_DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.7:../../textproc/py-cssselect

PYSETUPTESTARGS=	--run-tests

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.9.12
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.34
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
# fix for UnicodeEncodeError: 'ascii' codec can't encode characters
TEST_ENV+=	LC_ALL=en_US.UTF-8
