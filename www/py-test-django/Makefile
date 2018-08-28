# $NetBSD: Makefile,v 1.7 2018/08/28 11:02:37 adam Exp $

DISTNAME=	pytest-django-3.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-django/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pytest-django.readthedocs.io/
COMMENT=	Django plugin for pytest
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-test>=3.6:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.11.1:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
