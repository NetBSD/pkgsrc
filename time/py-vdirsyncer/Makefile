# $NetBSD: Makefile,v 1.4 2014/08/18 12:25:52 wiz Exp $

DISTNAME=	vdirsyncer-0.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	https://pypi.python.org/packages/source/v/vdirsyncer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/vdirsyncer/
COMMENT=	Synchronization tool for vdir
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-icalendar-[0-9]*:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt-[0-9]*:../../devel/py-requests-toolbelt

USE_LANGUAGES=	# none
INSTALLATION_DIRS=	share/example/${PKGBASE}
PLIST_SUBST+=	PKGBASE=${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/example.cfg ${DESTDIR}${PREFIX}/share/example/${PKGBASE}/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
