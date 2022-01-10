# $NetBSD: Makefile,v 1.18 2022/01/10 09:13:53 wiz Exp $

DISTNAME=	jonpy-0.06
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jonpy/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://jonpy.sourceforge.net/
COMMENT=	Tools for FastCGI/CGI Python programs
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.06

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
