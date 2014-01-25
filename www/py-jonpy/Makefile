# $NetBSD: Makefile,v 1.7 2014/01/25 10:30:29 wiz Exp $

DISTNAME=	jonpy-0.06
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jonpy/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://jonpy.sourceforge.net/
COMMENT=	Tools for FastCGI/CGI Python programs
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.06

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
