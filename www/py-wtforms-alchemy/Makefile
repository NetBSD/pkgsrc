# $NetBSD: Makefile,v 1.12 2024/03/06 21:27:04 wiz Exp $

DISTNAME=	WTForms-Alchemy-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-Alchemy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/wtforms-alchemy
COMMENT=	Generates WTForms forms from SQLAlchemy models
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-utils>=0.32.6:../../databases/py-sqlalchemy-utils
DEPENDS+=	${PYPKGPREFIX}-wtforms>=2.2:../../www/py-wtforms
DEPENDS+=	${PYPKGPREFIX}-wtforms-components>=0.9.2:../../www/py-wtforms-components
#TEST_DEPENDS+=	${PYPKGPREFIX}-enum34>=0:../../devel/py-enum34
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments>=1.2:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-jinja2>=1.2:../../textproc/py-jinja2
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=0.10:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-flexmock>=0.9.7:../../devel/py-flexmock
TEST_DEPENDS+=	${PYPKGPREFIX}-isort>=3.9.6:../../devel/py-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-natsort>=3.9.6:../../textproc/py-natsort
TEST_DEPENDS+=	${PYPKGPREFIX}-wtforms-test>=0:../../www/py-wtforms-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
