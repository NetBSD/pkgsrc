# $NetBSD: Makefile,v 1.6 2019/02/18 11:47:11 adam Exp $

DISTNAME=	pytest-httpbin-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-httpbin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kevin1024/pytest-httpbin
COMMENT=	Easily test your HTTP library against a local copy of httpbin
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httpbin-[0-9]*:../../www/py-httpbin
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
