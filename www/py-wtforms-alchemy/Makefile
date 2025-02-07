# $NetBSD: Makefile,v 1.14 2025/02/07 13:56:03 adam Exp $

DISTNAME=	wtforms_alchemy-0.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-Alchemy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/wtforms-alchemy
COMMENT=	Generates WTForms forms from SQLAlchemy models
LICENSE=	modified-bsd

WHEEL_NAME=	WTForms_Alchemy-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.4:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-utils>=0.40.0:../../databases/py-sqlalchemy-utils
DEPENDS+=	${PYPKGPREFIX}-wtforms>=3.1.0:../../www/py-wtforms
DEPENDS+=	${PYPKGPREFIX}-wtforms-components>=0.11.0:../../www/py-wtforms-components
TEST_DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-flexmock>=0.9.7:../../devel/py-flexmock
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments>=1.2:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-i18n>=0.8.2:../../databases/py-sqlalchemy-i18n
TEST_DEPENDS+=	${PYPKGPREFIX}-wtforms-test>=0.1.1:../../www/py-wtforms-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
