# $NetBSD: Makefile,v 1.59 2025/01/19 17:04:01 he Exp $

DISTNAME=	regex-2024.11.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/regex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mrabarnett/mrab-regex
COMMENT=	Alternative regular expression module, to replace re
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

# needs 'make install'
do-test:
	${PYTHONBIN} -m regex.test_regex

.include "../../lang/python/wheel.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
