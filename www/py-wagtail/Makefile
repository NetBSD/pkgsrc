# $NetBSD: Makefile,v 1.25 2024/02/16 22:17:07 adam Exp $

DISTNAME=	wagtail-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wagtail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wagtail.io/
COMMENT=	Django-based Content Management System
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.1.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-Willow>=1.6.2:../../graphics/py-Willow
DEPENDS+=	${PYPKGPREFIX}-anyascii>=0.1.5:../../textproc/py-anyascii
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.8:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django4
DEPENDS+=	${PYPKGPREFIX}-django-filter>=23.3:../../www/py-django-filter
DEPENDS+=	${PYPKGPREFIX}-django-modelcluster>=6.2.1:../../www/py-django-modelcluster
DEPENDS+=	${PYPKGPREFIX}-django-permissionedforms>=0.1:../../www/py-django-permissionedforms
DEPENDS+=	${PYPKGPREFIX}-django-taggit>=4.0:../../www/py-django-taggit
DEPENDS+=	${PYPKGPREFIX}-django-treebeard>=4.5.1:../../www/py-django-treebeard
DEPENDS+=	${PYPKGPREFIX}-djangorestframework>=3.11.1:../../www/py-djangorestframework
DEPENDS+=	${PYPKGPREFIX}-draftjs_exporter>=2.1.5:../../www/py-draftjs_exporter
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-l18n>=2018.5:../../time/py-l18n
DEPENDS+=	${PYPKGPREFIX}-laces>=0.1:../../www/py-laces
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=3.0.10:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-requests>=2.11.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-telepath>=0.3.1:../../www/py-telepath
TEST_DEPENDS+=	${PYPKGPREFIX}-boto3>=1.28:../../net/py-boto3
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=3.7.0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-doc8>=0.8.1:../../devel/py-doc8
TEST_DEPENDS+=	${PYPKGPREFIX}-ruff>=0.1.5:../../devel/py-ruff
TEST_DEPENDS+=	${PYPKGPREFIX}-factory_boy>=3.2:../../devel/py-factory_boy
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3.8:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-polib>=1.1:../../devel/py-polib
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=2014.7:../../time/py-pytz

# Not packaged test dependencies as of 6.0:
#  azure-mgmt-cdn>=12.0
#  azure-mgmt-frontdoor>=1.0
#  curlylint==0.13.1
#  django-pattern-library>=0.7
#  djhtml==3.0.6
#  semgrep==1.40.0
#  tblib<3.0,>=2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

REPLACE_PYTHON+=	wagtail/project_template/manage.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wagtail wagtail-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} run -m django test --settings=wagtail.test.settings

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
