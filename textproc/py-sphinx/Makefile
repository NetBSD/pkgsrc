# $NetBSD: Makefile,v 1.1.1.1 2009/01/31 05:31:13 markd Exp $
#

DISTNAME=	Sphinx-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/S/Sphinx/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://sphinx.pocoo.org/
COMMENT=	Python documentation generator

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.4:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
