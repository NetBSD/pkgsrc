# $NetBSD: Makefile,v 1.2 2008/09/04 17:17:15 epg Exp $

DISTNAME=	Paste-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/P/Paste/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pythonpaste.org/
COMMENT=	Middleware for Python WSGI applications

PKG_DESTDIR_SUPPORT=		user-destdir

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c8:../../devel/py-setuptools

PYDISTUTILSPKG=	yes

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

# XXX I think this can't work because of the 'next;' in pyversion.mk.
PRINT_PLIST_AWK+=	{ gsub(/py${PYVERSSUFFIX}/, "py$${PYVERSSUFFIX}") }
