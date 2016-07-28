# $NetBSD: Makefile,v 1.9 2016/07/28 12:59:41 mef Exp $

DISTNAME=		khal-0.8.2
CATEGORIES=		time net
MASTER_SITES=		${MASTER_SITE_PYPI:=k/khal/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/geier/khal
COMMENT=		CLI calendar application built around CalDAV
LICENSE=		mit

DEPENDS+=		${PYPKGPREFIX}-click>=3.2:../../devel/py-click
DEPENDS+=		${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=		${PYPKGPREFIX}-icalendar>=2.0.1:../../time/py-icalendar
DEPENDS+=		${PYPKGPREFIX}-pkginfo-[0-9]*:../../devel/py-pkginfo
BUILD_DEPENDS+=		${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=		${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=		${PYPKGPREFIX}-tzlocal-[0-9]*:../../time/py-tzlocal
DEPENDS+=		${PYPKGPREFIX}-urwid>=1.1.0:../../devel/py-urwid
DEPENDS+=		${PYPKGPREFIX}-vdirsyncer-[0-9]*:../../time/py-vdirsyncer
DEPENDS+=		${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg
# not needed, but recommended, so let's just depend on it
DEPENDS+=		${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle
# test dependency, not packaged yet
# freezegun

PYTHON_VERSIONS_INCOMPATIBLE=	27 # time/py-vdirsyncer

PYTHON_VERSIONED_DEPENDENCIES=	dateutil

INSTALLATION_DIRS=	share/doc/khal
REPLACE_PYTHON+=	khal/*/*.py
REPLACE_PYTHON+=	khal/*.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/khal.conf.sample ${DESTDIR}${PREFIX}/share/doc/khal

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
