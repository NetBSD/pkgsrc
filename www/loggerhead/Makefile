# $NetBSD: Makefile,v 1.2 2008/12/26 19:51:55 epg Exp $

DISTNAME=	loggerhead-${VER}
CATEGORIES=	www scm
MASTER_SITES=	http://launchpad.net/loggerhead/${VER}/${VER}/+download/
VER=		1.10

# 1.10 distfile contains no top-level directory.
EXTRACT_DIR=	${WRKSRC}

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	https://launchpad.net/loggerhead
COMMENT=	Web viewer for Bazaar branches

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	bzr>=1.6:../../devel/bzr
DEPENDS+=	${PYPKGPREFIX}-Paste>=1.2:../../www/py-paste
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c8:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-SimpleTAL>=4.1:../../www/py-simpletal
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

PYDISTUTILSPKG=	yes
# Requires wsgi, which is available for older versions of Python, but not in
# pkgsrc yet.  Also requires 'sqlite3', which seems not to be available
# separately (py-sqlite2 is for sqlite3 but is 'pysqlite2').
PYTHON_VERSIONS_ACCEPTED=25

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
