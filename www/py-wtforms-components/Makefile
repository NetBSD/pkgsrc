# $NetBSD: Makefile,v 1.10 2025/02/07 09:44:56 adam Exp $

DISTNAME=	wtforms_components-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-Components/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/wtforms-components
COMMENT=	Additional fields, validators and widgets for WTForms
LICENSE=	modified-bsd

WHEEL_NAME=	WTForms_Components-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-intervals>=0.6.0:../../math/py-intervals
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=1.0.0:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-validators>=0.21:../../textproc/py-validators
DEPENDS+=	${PYPKGPREFIX}-wtforms>=3.1.0:../../www/py-wtforms
TEST_DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-flexmock>=0.9.7:../../devel/py-flexmock
TEST_DEPENDS+=	${PYPKGPREFIX}-wtforms-test>=0.1.1:../../www/py-wtforms-test

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
