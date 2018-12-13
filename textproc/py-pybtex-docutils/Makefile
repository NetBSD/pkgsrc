# $NetBSD: Makefile,v 1.2 2018/12/13 20:46:09 adam Exp $

DISTNAME=	pybtex-docutils-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybtex-docutils/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mcmtroffaes/pybtex-docutils
COMMENT=	Docutils backend for pybtex
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.8:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pybtex>=0.16:../../textproc/py-pybtex
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
