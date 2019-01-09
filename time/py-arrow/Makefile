# $NetBSD: Makefile,v 1.7 2019/01/09 09:04:04 adam Exp $

DISTNAME=	arrow-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arrow/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://crsmithdev.com/arrow/
COMMENT=	Better dates and times for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-chai-[0-9]*:../../devel/py-chai

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
