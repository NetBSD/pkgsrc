# $NetBSD: Makefile,v 1.6 2025/12/27 08:39:40 adam Exp $

DISTNAME=	python_json_logger-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-json-logger/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nhairs/python-json-logger
COMMENT=	Python library adding a JSON log formatter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
