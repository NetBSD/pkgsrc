# $NetBSD: Makefile,v 1.14 2019/04/26 14:12:48 maya Exp $

DISTNAME=	jonpy-0.06
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jonpy/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://jonpy.sourceforge.net/
COMMENT=	Tools for FastCGI/CGI Python programs
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.06

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
