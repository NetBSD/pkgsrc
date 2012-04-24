# $NetBSD: Makefile,v 1.3 2012/04/24 11:57:23 obache Exp $
#

DISTNAME=	webcolors-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://bitbucket.org/ubernostrum/webcolors/downloads/ \
		http://pypi.python.org/packages/source/w/webcolors/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.bitbucket.org/ubernostrum/webcolors/overview/
COMMENT=	Library for working with color specifications for HTML and CSS
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
