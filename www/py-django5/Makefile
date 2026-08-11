# $NetBSD: Makefile,v 1.5 2026/08/11 05:53:43 adam Exp $

DISTNAME=	django-5.2.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://www.djangoproject.com/m/releases/${PKGVERSION_NOREV:R}/
MASTER_SITES+=	${MASTER_SITE_PYPI:=D/Django/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.djangoproject.com/
COMMENT=	Django, a high-level Python Web framework
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asgiref>=3.8.1:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.3.1:../../databases/py-sqlparse

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	django-admin
REPLACE_PYTHON+=	django/conf/project_template/manage.py-tpl

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
