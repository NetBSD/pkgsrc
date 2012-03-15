# $NetBSD: Makefile,v 1.9 2012/03/15 11:53:44 obache Exp $

DISTNAME=	loggerhead-${VER}
PKGREVISION=	1
CATEGORIES=	www scm
MASTER_SITES=	http://launchpad.net/loggerhead/1.18/${VER}/+download/
VER=		1.18.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/loggerhead
COMMENT=	Web viewer for Bazaar branches
LICENSE=	gnu-gpl-v2 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	bzr>=1.17:../../devel/bzr
DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-Paste>=1.2:../../www/py-paste
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy>=1.3:../../www/py-PasteDeploy
DEPENDS+=	${PYPKGPREFIX}-SimpleTAL>=4.1:../../www/py-simpletal
DEPENDS+=	${PYPKGPREFIX}-flup-[0-9]*:../../www/py-flup

.include "../../lang/python/pyversion.mk"

.if defined(PYPACKAGE) && ${PYPACKAGE} == "python24"
DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2:../../databases/py-sqlite2
.else
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
