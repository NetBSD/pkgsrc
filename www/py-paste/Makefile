# $NetBSD: Makefile,v 1.13 2015/07/16 11:36:20 wiz Exp $

DISTNAME=	Paste-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/P/Paste/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pythonpaste.org/
COMMENT=	Middleware for Python WSGI applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
