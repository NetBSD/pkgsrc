# $NetBSD: Makefile,v 1.21 2023/09/01 07:20:53 jperkin Exp $

DISTNAME=	wagtail-4.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wagtail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wagtail.io/
COMMENT=	Django-based Content Management System
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-django-filter>=2.2.0:../../www/py-django-filter
DEPENDS+=	${PYPKGPREFIX}-django-modelcluster>=6.0<7.0:../../www/py-django-modelcluster
DEPENDS+=	${PYPKGPREFIX}-django-taggit>=2.0<4.0:../../www/py-django-taggit
DEPENDS+=	${PYPKGPREFIX}-django-treebeard>=4.5.1<5.0:../../www/py-django-treebeard
DEPENDS+=	${PYPKGPREFIX}-djangorestframework>=3.11.1<4.0:../../www/py-djangorestframework
DEPENDS+=	${PYPKGPREFIX}-Pillow>=4.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-Willow>=1.6:../../graphics/py-Willow
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.8<5.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999<2:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04.14<2.0:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-draftjs_exporter>=2.1.5<4.2:../../www/py-draftjs_exporter
DEPENDS+=	${PYPKGPREFIX}-requests>=2.11.1<3.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-l18n>=2018.5:../../time/py-l18n
DEPENDS+=	${PYPKGPREFIX}-anyascii>=0.1.5:../../textproc/py-anyascii
DEPENDS+=	${PYPKGPREFIX}-openpyxl>=3.0.10<4.0:../../textproc/py-openpyxl
DEPENDS+=	${PYPKGPREFIX}-tablib>=1.4:../../textproc/py-tablib
DEPENDS+=	${PYPKGPREFIX}-xlsxwriter>=1.2.8:../../textproc/py-xlsxwriter
DEPENDS+=	${PYPKGPREFIX}-django-permissionedforms-[0-9]*:../../www/py-django-permissionedforms
DEPENDS+=	${PYPKGPREFIX}-telepath>=0.1.1<1:../../www/py-telepath
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-factory_boy-[0-9]*:../../devel/py-factory_boy
TEST_DEPENDS+=	${PYPKGPREFIX}-boto3>=1.16:../../net/py-boto3
TEST_DEPENDS+=	${PYPKGPREFIX}-elasticsearch>=5.0:../../databases/py-elasticsearch
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3.8:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-polib>=1.1<2.0:../../devel/py-polib
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0<3.2:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=2014.7:../../time/py-pytz

# Not packaged test dependencies as of 4.2.2:
#    azure-mgmt-cdn>=12.0<13.0
#    azure-mgmt-frontdoor>=1.0<1.1

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_PKG_RESOURCES=	yes

REPLACE_PYTHON+=	wagtail/project_template/manage.py

pre-install:
	${FIND} ${WRKSRC} -name '*.orig' -delete

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} run -m django test --settings=wagtail.tests.settings

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
