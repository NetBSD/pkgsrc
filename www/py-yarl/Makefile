# $NetBSD: Makefile,v 1.10 2018/02/20 09:29:05 adam Exp $

DISTNAME=	yarl-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yarl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/yarl/
COMMENT=	Yet another URL library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-multidict>=2.0:../../databases/py-multidict

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
