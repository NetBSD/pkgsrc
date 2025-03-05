# $NetBSD: Makefile,v 1.11 2025/03/05 10:59:57 wiz Exp $

DISTNAME=	wtforms_components-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-Components/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/wtforms-components
COMMENT=	Additional fields, validators and widgets for WTForms
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
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
