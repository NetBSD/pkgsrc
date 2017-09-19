# $NetBSD: Makefile,v 1.48 2017/09/19 11:01:45 wiz Exp $

DISTNAME=	lxml-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxml.de/
COMMENT=	Python binding for libxml2 and libxslt
LICENSE=	modified-bsd

# as of 3.6.1, two test failures on NetBSD, see
# https://bugs.launchpad.net/lxml/+bug/1522052
# new error since 3.8.0
# https://bugs.launchpad.net/lxml/+bug/1710409
TEST_TARGET=	test_inplace

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.7.8
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.26
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
# needed for "make test" with python-3.x -- fixes first two errors noted above
MAKE_ENV+=	LC_ALL=en_US.UTF-8
