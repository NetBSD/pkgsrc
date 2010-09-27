# $NetBSD: Makefile,v 1.7 2010/09/27 10:29:22 adam Exp $

DISTNAME=	Sphinx-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/S/Sphinx/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://sphinx.pocoo.org/
COMMENT=	Python documentation generator
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.5:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
