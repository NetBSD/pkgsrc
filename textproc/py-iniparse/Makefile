# $NetBSD: Makefile,v 1.14 2020/06/18 21:45:06 adam Exp $

DISTNAME=	iniparse-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/iniparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/candlepin/python-iniparse
COMMENT=	Better INI parser for Python
LICENSE=	mit AND python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
