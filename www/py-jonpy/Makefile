# $NetBSD: Makefile,v 1.16 2020/01/18 23:35:45 rillig Exp $

DISTNAME=	jonpy-0.06
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jonpy/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://jonpy.sourceforge.net/
COMMENT=	Tools for FastCGI/CGI Python programs
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.06

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
