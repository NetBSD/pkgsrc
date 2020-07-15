# $NetBSD: Makefile,v 1.28 2020/07/15 07:38:42 adam Exp $

DISTNAME=	Paste-3.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Paste/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonpaste.readthedocs.io/
COMMENT=	Middleware for Python WSGI applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-flup-[0-9]*:../../www/py-flup

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
