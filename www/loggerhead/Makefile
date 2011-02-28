# $NetBSD: Makefile,v 1.5 2011/02/28 14:53:06 wiz Exp $

DISTNAME=	loggerhead-${VER}
PKGREVISION=	1
CATEGORIES=	www scm
MASTER_SITES=	http://launchpad.net/loggerhead/${VER}/${VER}/+download/
VER=		1.17

WRKSRC=		${WRKDIR}/loggerhead

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/loggerhead
COMMENT=	Web viewer for Bazaar branches

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	bzr>=1.13:../../devel/bzr
DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-Paste>=1.2:../../www/py-paste
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy>=1.3:../../www/py-PasteDeploy
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
