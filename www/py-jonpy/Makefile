# $NetBSD: Makefile,v 1.1.1.1 2006/07/02 14:33:22 joerg Exp $
#

DISTNAME=	jonpy-0.06
PKGNAME=	${PYPKGPREFIX}-jonpy-0.06
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jonpy/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://jonpy.sourceforge.net
COMMENT=	Tools for FastCGI/CGI Python programs

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
