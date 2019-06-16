# $NetBSD: Makefile,v 1.10 2019/06/16 14:08:03 adam Exp $

DISTNAME=	arrow-0.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arrow/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/crsmithdev/arrow
COMMENT=	Better dates and times for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-chai-[0-9]*:../../devel/py-chai

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
