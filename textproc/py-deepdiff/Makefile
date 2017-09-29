# $NetBSD: Makefile,v 1.3 2017/09/29 11:06:32 adam Exp $

DISTNAME=	deepdiff-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deepdiff/}

MAINTAINER=	sep@zepworks.com
HOMEPAGE=	https://github.com/seperman/deepdiff
COMMENT=	Deep Difference and Search of any Python object/data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jsonpickle-[0-9]*:../../textproc/py-jsonpickle

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
