# $NetBSD: Makefile,v 1.28 2020/03/22 22:42:13 rillig Exp $

DISTNAME=	Jinja2-2.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Jinja2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jinja.pocoo.org/
COMMENT=	Small but fast and easy to use stand-alone template engine
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=0.23:../../textproc/py-markupsafe
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=		# none

.include "../../lang/python/pyversion.mk"

# async byte-compilation fails for Python < 3.6
# see https://github.com/pallets/jinja/issues/643
PLIST_VARS+=	async
.if ${_PYTHON_VERSION} != 27
PLIST.async=	yes
.endif

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
