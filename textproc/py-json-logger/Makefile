# $NetBSD: Makefile,v 1.2 2025/02/06 09:48:37 adam Exp $

DISTNAME=	python_json_logger-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-json-logger/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nhairs/python-json-logger
COMMENT=	Python library adding a JSON log formatter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>0:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
