# $NetBSD: Makefile,v 1.3 2020/03/15 22:45:25 adam Exp $

DISTNAME=	ujson-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/ujson/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/esnme/ultrajson
COMMENT=	Ultra fast JSON encoder and decoder for Python
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
