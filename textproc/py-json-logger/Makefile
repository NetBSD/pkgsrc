# $NetBSD: Makefile,v 1.5 2025/10/09 08:07:29 wiz Exp $

DISTNAME=	python_json_logger-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//:S/_/-/}
PKGREVISION=	1
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
