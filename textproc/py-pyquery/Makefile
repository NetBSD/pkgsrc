# $NetBSD: Makefile,v 1.1 2014/05/16 01:06:29 rodent Exp $

DISTNAME=	pyquery-1.2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	https://pypi.python.org/packages/source/p/pyquery/
EXTRACT_SUFX=	.zip

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/gawel/pyquery
COMMENT=	Python jquery-like library
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml>=2.1:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-cssselect-[0-9]*:../../textproc/py-cssselect

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
