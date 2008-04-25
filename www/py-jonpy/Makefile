# $NetBSD: Makefile,v 1.3 2008/04/25 20:39:13 joerg Exp $
#

DISTNAME=	jonpy-0.06
PKGNAME=	${PYPKGPREFIX}-jonpy-0.06
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jonpy/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://jonpy.sourceforge.net
COMMENT=	Tools for FastCGI/CGI Python programs

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
