# $NetBSD: Makefile,v 1.5 2019/07/13 09:21:59 adam Exp $

DISTNAME=	deepdiff-4.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/deepdiff/}

MAINTAINER=	sep@zepworks.com
HOMEPAGE=	https://github.com/seperman/deepdiff
COMMENT=	Deep Difference and Search of any Python object/data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jsonpickle>=1.0:../../textproc/py-jsonpickle
DEPENDS+=	${PYPKGPREFIX}-mmh3-[0-9]*:../../devel/py-mmh3
DEPENDS+=	${PYPKGPREFIX}-ordered-set>=3.1:../../devel/py-ordered-set

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
