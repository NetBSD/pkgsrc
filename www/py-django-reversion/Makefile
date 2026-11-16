# $NetBSD: Makefile,v 1.46 2026/11/16 10:50:41 adam Exp $

DISTNAME=	django_reversion-6.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-reversion/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/etianen/django-reversion
COMMENT=	Version control facilities for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 312
DEPENDS+=	${PYPKGPREFIX}-django>=5.2<6:../../www/py-django5
.else
DEPENDS+=	${PYPKGPREFIX}-django>=5.2:../../www/py-django
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
