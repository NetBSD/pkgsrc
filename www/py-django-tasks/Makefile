# $NetBSD: Makefile,v 1.4 2025/12/26 12:44:38 adam Exp $

DISTNAME=	django_tasks-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-tasks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/RealOrangeOne/django-tasks
COMMENT=	Background workers and tasks in Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-stubs-ext-[0-9]*:../../www/py-django-stubs-ext
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
