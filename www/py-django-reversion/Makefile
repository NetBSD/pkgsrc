# $NetBSD: Makefile,v 1.45 2026/11/02 22:29:06 wiz Exp $

DISTNAME=	django_reversion-6.5.1
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
DEPENDS+=	${PYPKGPREFIX}-django>=4.2<6:../../www/py-django5
.else
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
