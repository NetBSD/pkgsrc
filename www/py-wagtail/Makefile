# $NetBSD: Makefile,v 1.10 2022/01/04 20:55:37 wiz Exp $

DISTNAME=	wagtail-2.12.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wagtail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wagtail.io/
COMMENT=	Django-based Content Management System
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=2.2<3.2:../../www/py-django2
DEPENDS+=	${PYPKGPREFIX}-django-filter>=2.2.0:../../www/py-django-filter
DEPENDS+=	${PYPKGPREFIX}-django-modelcluster>=5.1<6.0:../../www/py-django-modelcluster
DEPENDS+=	${PYPKGPREFIX}-django-taggit>=1.0<2.0:../../www/py-django-taggit
DEPENDS+=	${PYPKGPREFIX}-django-treebeard>=4.2<5.0:../../www/py-django-treebeard
DEPENDS+=	${PYPKGPREFIX}-djangorestframework>=3.11.1<4.0:../../www/py-djangorestframework
DEPENDS+=	${PYPKGPREFIX}-Pillow>=4.0.0<9.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-Willow>=1.4<1.5.0:../../graphics/py-Willow
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.8<5.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999<2:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04.14<2.0:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-draftjs_exporter>=2.1.5<4.2:../../www/py-draftjs_exporter
DEPENDS+=	${PYPKGPREFIX}-requests>=2.11.1<3.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-l18n>=2018.5:../../time/py-l18n
DEPENDS+=	${PYPKGPREFIX}-tablib>=1.4:../../textproc/py-tablib
DEPENDS+=	${PYPKGPREFIX}-xlsxwriter>=1.2.8<2.0:../../textproc/py-xlsxwriter
TEST_DEPENDS+=	${PYPKGPREFIX}-boto3-[0-9]*:../../net/py-boto3
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-elasticsearch-[0-9]*:../../databases/py-elasticsearch
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-openpyxl-[0-9]*:../../textproc/py-openpyxl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-django2

REPLACE_PYTHON+=	wagtail/project_template/manage.py

pre-install:
	${FIND} ${WRKSRC} -name '*.orig' -delete

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} run -m django test --settings=wagtail.tests.settings

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
