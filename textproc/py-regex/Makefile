# $NetBSD: Makefile,v 1.52 2024/04/30 18:10:13 adam Exp $

DISTNAME=	regex-2024.4.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/regex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mrabarnett/mrab-regex
COMMENT=	Alternative regular expression module, to replace re
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs 'make install'
do-test:
	${PYTHONBIN} -m regex.test_regex

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
