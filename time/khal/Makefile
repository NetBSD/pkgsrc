# $NetBSD: Makefile,v 1.1 2014/07/22 17:08:46 wiz Exp $

DISTNAME=		khal-0.2.0
CATEGORIES=		time net
MASTER_SITES=		-https://github.com/geier/khal/archive/${DISTNAME:S/khal-/v/}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/geier/khal
COMMENT=		CLI calendar application built around CalDAV
LICENSE=		mit

DEPENDS+=		${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg
DEPENDS+=		${PYPKGPREFIX}-icalendar>=2.0.1:../../time/py-icalendar
DEPENDS+=		${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=		${PYPKGPREFIX}-lxml>=2:../../textproc/py-lxml
DEPENDS+=		${PYPKGPREFIX}-requests>=0.10:../../devel/py-requests
# SimpleFocusListWalker is in urwid 1.1.0
DEPENDS+=		${PYPKGPREFIX}-urwid>=1.1.0:../../devel/py-urwid
# not needed, but recommended, so let's just depend on them
DEPENDS+=		${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=		${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle

PYTHON_VERSIONED_DEPENDENCIES=	dateutil
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.2.0

INSTALLATION_DIRS=	share/doc/khal
REPLACE_PYTHON+=	khal/*/*.py
REPLACE_PYTHON+=	khal/*.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/khal.conf.sample ${DESTDIR}${PREFIX}/share/doc/khal

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
