# $NetBSD: Makefile,v 1.2 2008/04/25 19:18:23 tnn Exp $
#

DISTNAME=	urlgrabber-3.1.0
CATEGORIES=	www devel
MASTER_SITES=	http://linux.duke.edu/projects/urlgrabber/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.duke.edu/projects/urlgrabber/download/
COMMENT=	Python package that drastically simplifies the fetching of files

PKG_DESTDIR_SUPPORT=		user-destdir

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	25 24 23
PYDISTUTILSPKG=			yes
PY_PATCHPLIST=			yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
