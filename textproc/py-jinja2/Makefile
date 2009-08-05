# $NetBSD: Makefile,v 1.1.1.1 2009/08/05 10:15:09 markd Exp $
#

DISTNAME=	Jinja2-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/J/Jinja2/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://jinja.pocoo.org/2/
COMMENT=	Small but fast and easy to use stand-alone template engine
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

# move doc directory so its not installed
post-patch:
	mv ${WRKSRC}/docs/_build ${WRKSRC}/docs/__build

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
