# $NetBSD: Makefile,v 1.3 2022/06/30 11:18:54 nia Exp $

DISTNAME=	Jinja2-2.11.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=J/Jinja2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jinja.palletsprojects.com/
COMMENT=	Small but fast and easy to use stand-alone template engine
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=0.23:../../textproc/py27-markupsafe
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
