# $NetBSD: Makefile,v 1.107 2024/05/29 16:34:39 adam Exp $

DISTNAME=	lxml-5.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxml.de/
COMMENT=	Python binding for libxml2 and libxslt
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.7:../../textproc/py-cssselect

USE_CC_FEATURES=	c99

# pycore_frame.h:134:5: error:
# 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=		gnu99

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.9.12
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.34
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
# fix for UnicodeEncodeError: 'ascii' codec can't encode characters
TEST_ENV+=	LC_ALL=en_US.UTF-8
