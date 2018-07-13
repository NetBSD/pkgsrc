# $NetBSD: Makefile,v 1.4 2018/07/13 07:13:49 adam Exp $

DISTNAME=	alabaster-0.7.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/alabaster/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bitprophet/alabaster
COMMENT=	Configurable sidebar-enabled Sphinx theme
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
