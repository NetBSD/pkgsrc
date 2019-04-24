# $NetBSD: Makefile,v 1.1 2019/04/24 15:50:43 adam Exp $

DISTNAME=	sphinx-issues-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-issues/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sloria/sphinx-issues
COMMENT=	Sphinx extension for linking to an issue tracker
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
