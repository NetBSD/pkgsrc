# $NetBSD: Makefile,v 1.17 2024/02/21 19:44:26 adam Exp $

DISTNAME=	Mezzanine-6.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mezzanine/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mezzanine.jupo.org/
COMMENT=	Open source content management platform on Django
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-Pillow>=7:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.5.3:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-bleach>=5:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-chardet>=4:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-contrib-comments>=2.0:../../www/py-django-contrib-comments
DEPENDS+=	${PYPKGPREFIX}-filebrowser_safe>=1.1.1:../../www/py-filebrowser_safe
DEPENDS+=	${PYPKGPREFIX}-grappelli_safe>=1.1.1:../../www/py-grappelli_safe
DEPENDS+=	${PYPKGPREFIX}-pytz>=2021.1:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=1.3:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=2:../../time/py-tzlocal
TEST_DEPENDS+=	${PYPKGPREFIX}-flakes>=0.6.1:../../devel/py-flakes
TEST_DEPENDS+=	${PYPKGPREFIX}-pep8>=1.4.1:../../devel/py-pep8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

REPLACE_PYTHON+=	mezzanine/bin/mezzanine_project.py
REPLACE_PYTHON+=	mezzanine/project_template/manage.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} mezzanine-project mezzanine-project-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
