# $NetBSD: Makefile,v 1.11 2017/01/01 14:44:05 wiz Exp $

DISTNAME=	jonpy-0.06
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jonpy/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://jonpy.sourceforge.net/
COMMENT=	Tools for FastCGI/CGI Python programs
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.06

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
