# $NetBSD: Makefile,v 1.2 2010/06/05 23:54:22 markd Exp $
#

DISTNAME=	Jinja2-2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/J/Jinja2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jinja.pocoo.org/2/
COMMENT=	Small but fast and easy to use stand-alone template engine
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

# move doc directory so its not installed
post-patch:
	mv ${WRKSRC}/docs/_build ${WRKSRC}/docs/__build

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
