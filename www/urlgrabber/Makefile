# $NetBSD: Makefile,v 1.7 2011/06/14 09:37:22 obache Exp $
#

DISTNAME=	urlgrabber-3.1.0
PKGREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	http://urlgrabber.baseurl.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://urlgrabber.baseurl.org/
COMMENT=	Python package that drastically simplifies the fetching of files

PKG_DESTDIR_SUPPORT=		user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=			yes
PY_PATCHPLIST=			yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
