# $NetBSD: Makefile,v 1.12 2014/05/09 07:37:26 wiz Exp $

DISTNAME=	urlgrabber-3.1.0
PKGREVISION=	3
CATEGORIES=	www devel
MASTER_SITES=	http://urlgrabber.baseurl.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://urlgrabber.baseurl.org/
COMMENT=	Python package that drastically simplifies the fetching of files

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 3.1.0

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
