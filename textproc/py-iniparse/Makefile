# $NetBSD: Makefile,v 1.15 2022/01/04 20:54:56 wiz Exp $

DISTNAME=	iniparse-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
