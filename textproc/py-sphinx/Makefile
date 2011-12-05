# $NetBSD: Makefile,v 1.12 2011/12/05 15:34:12 dholland Exp $

DISTNAME=	Sphinx-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/S/Sphinx/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://sphinx.pocoo.org/
COMMENT=	Python documentation generator
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	24

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.8.1:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
