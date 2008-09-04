# $NetBSD: Makefile,v 1.1.1.1 2008/09/04 16:49:17 epg Exp $

DISTNAME=	Paste-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/P/Paste/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pythonpaste.org/
COMMENT=	Middleware for Python WSGI applications

PKG_DESTDIR_SUPPORT=		user-destdir

PYDISTUTILSPKG=			yes
# Requires setuptools; if adding other versions, fix PLIST, too.
PYTHON_VERSIONS_ACCEPTED=	25

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
