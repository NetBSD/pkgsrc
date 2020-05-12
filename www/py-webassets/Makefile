# $NetBSD: Makefile,v 1.11 2020/05/12 15:59:07 kleink Exp $

DISTNAME=	webassets-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/webassets/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://webassets.readthedocs.io/
COMMENT=	Asset management for Python web development
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

REPLACE_PYTHON+=	src/webassets/filter/rjsmin/rjsmin.py

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
