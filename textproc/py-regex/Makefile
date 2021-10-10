# $NetBSD: Makefile,v 1.36 2021/10/10 02:48:48 gutteridge Exp $

DISTNAME=	regex-2021.9.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/regex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mrabarnett/mrab-regex
COMMENT=	Alternative regular expression module, to replace re
LICENSE=	python-software-foundation

do-test:
	${PYTHONBIN} -m regex.test_regex

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
