# $NetBSD: Makefile,v 1.3 2017/07/20 17:03:46 adam Exp $

DISTNAME=	mistune-0.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mistune/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lepture/mistune
COMMENT=	The fastest markdown parser in pure Python
LICENSE=	modified-bsd

USE_LANGUAGES=	c

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
