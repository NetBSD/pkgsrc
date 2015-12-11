# $NetBSD: Makefile,v 1.2 2015/12/11 19:23:57 joerg Exp $

DISTNAME=	numpydoc-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/n/numpydoc/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/numpydoc
COMMENT=	Sphinx extension to support docstrings in Numpy format
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.8:../../textproc/py-sphinx

USE_LANGUAGES=	# none

post-extract:
	chmod -R a+rX ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
