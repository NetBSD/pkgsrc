# $NetBSD: Makefile,v 1.5 2010/06/01 21:22:10 markd Exp $
#

DISTNAME=	Sphinx-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/S/Sphinx/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://sphinx.pocoo.org/
COMMENT=	Python documentation generator
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.4:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
