# $NetBSD: Makefile,v 1.3 2009/08/05 10:41:17 markd Exp $
#

DISTNAME=	Sphinx-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/S/Sphinx/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://sphinx.pocoo.org/
COMMENT=	Python documentation generator

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.4:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
