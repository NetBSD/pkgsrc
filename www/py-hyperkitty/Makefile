# $NetBSD: Makefile,v 1.4 2023/11/07 22:38:09 wiz Exp $

DISTNAME=	HyperKitty-1.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=H/HyperKitty/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	Web interface to access GNU Mailman v3 archives
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-isort>=0:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-django-mailman3>=1.3.8:../../www/py-django-mailman3
DEPENDS+=	${PYPKGPREFIX}-django-gravatar2>=1.0.6:../../www/py-django-gravatar2
DEPENDS+=	${PYPKGPREFIX}-djangorestframework>=3.0.0:../../www/py-djangorestframework
DEPENDS+=	${PYPKGPREFIX}-robot-detection>=0.3:../../www/py-robot-detection
DEPENDS+=	${PYPKGPREFIX}-pytz>=2012:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-django-compressor>=1.3:../../www/py-django-compressor
DEPENDS+=	${PYPKGPREFIX}-mailmanclient>=3.3.3:../../mail/py-mailmanclient
DEPENDS+=	${PYPKGPREFIX}-mistune>=2.0.0:../../textproc/py-mistune
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.0:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-django-haystack>=2.8.0:../../www/py-django-haystack
DEPENDS+=	${PYPKGPREFIX}-django-extensions>=1.3.7:../../www/py-django-extensions
DEPENDS+=	${PYPKGPREFIX}-flufl.lock>=4.0:../../devel/py-flufl.lock
DEPENDS+=	${PYPKGPREFIX}-django-q>=1.0.0:../../www/py-django-q
DEPENDS+=	${PYPKGPREFIX}-Whoosh-[0-9]*:../../textproc/py-Whoosh
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-django-debug-toolbar-[0-9]*:../../www/py-django-debug-toolbar

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
