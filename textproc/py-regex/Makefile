# $NetBSD: Makefile,v 1.44 2022/11/03 12:49:38 adam Exp $

DISTNAME=	regex-2022.10.31
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/regex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mrabarnett/mrab-regex
COMMENT=	Alternative regular expression module, to replace re
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	${PYTHONBIN} -m regex.test_regex

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
