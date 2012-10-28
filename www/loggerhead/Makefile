# $NetBSD: Makefile,v 1.11 2012/10/28 06:30:21 asau Exp $

DISTNAME=	loggerhead-${VER}
PKGREVISION=	1
CATEGORIES=	www scm
MASTER_SITES=	http://launchpad.net/loggerhead/1.18/${VER}/+download/
VER=		1.18.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/loggerhead
COMMENT=	Web viewer for Bazaar branches
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	bzr>=1.17:../../devel/bzr
DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.0:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-Paste>=1.2:../../www/py-paste
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy>=1.3:../../www/py-PasteDeploy
DEPENDS+=	${PYPKGPREFIX}-SimpleTAL>=4.1:../../www/py-simpletal
DEPENDS+=	${PYPKGPREFIX}-flup-[0-9]*:../../www/py-flup

.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
