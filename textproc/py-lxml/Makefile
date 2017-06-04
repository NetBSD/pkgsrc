# $NetBSD: Makefile,v 1.45 2017/06/04 19:17:51 adam Exp $

DISTNAME=	lxml-3.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxml.de/
COMMENT=	Python binding for libxml2 and libxslt
LICENSE=	modified-bsd

# as of 3.6.1, two test failures on NetBSD, see
# https://bugs.launchpad.net/lxml/+bug/1522052
# third error in 3.6.1
# https://bugs.launchpad.net/lxml/+bug/1608479
# two more errors since 3.7.2
# https://bugs.launchpad.net/lxml/+bug/1655054
TEST_TARGET=	test_inplace

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.7.8
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.26
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
# needed for "make test" with python-3.x -- fixes first two errors noted above
#MAKE_ENV+=     LC_ALL=en_US.UTF-8
