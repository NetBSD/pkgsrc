# $NetBSD: Makefile,v 1.13 2022/01/05 15:41:31 wiz Exp $

DISTNAME=	webassets-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/webassets/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://webassets.readthedocs.io/
COMMENT=	Asset management for Python web development
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# empty

REPLACE_PYTHON+=	src/webassets/filter/rjsmin/rjsmin.py

USE_PKG_RESOURCES=	yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
