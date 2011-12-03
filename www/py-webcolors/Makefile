# $NetBSD: Makefile,v 1.2 2011/12/03 00:02:17 joerg Exp $
#

DISTNAME=	webcolors-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://bitbucket.org/ubernostrum/webcolors/downloads/ \
		http://pypi.python.org/packages/source/w/webcolors/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.bitbucket.org/ubernostrum/webcolors/overview/
COMMENT=	Library for working with color specifications for HTML and CSS
#LICENSE=	# just OSI Approved BSD License

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
