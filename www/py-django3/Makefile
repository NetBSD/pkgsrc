# $NetBSD: Makefile,v 1.24 2022/01/05 10:09:53 wiz Exp $

DISTNAME=	Django-3.2.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	https://www.djangoproject.com/m/releases/${PKGVERSION_NOREV:R}/
MASTER_SITES+=	${MASTER_SITE_PYPI:=D/Django/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.djangoproject.com/
COMMENT=	Django, a high-level Python Web framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-asgiref>=3.3.2:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sqlparse>=0.2.2:../../databases/py-sqlparse

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	django/bin/django-admin.py
REPLACE_PYTHON+=	django/conf/project_template/manage.py-tpl

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} django-admin django-admin-${PYVERSSUFFIX} && \
	${MV} django-admin.py django-admin-${PYVERSSUFFIX}.py || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
