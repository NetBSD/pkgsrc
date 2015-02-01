# $NetBSD: Makefile,v 1.14 2015/02/01 19:52:51 wiz Exp $

DISTNAME=	vdirsyncer-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	https://pypi.python.org/packages/source/v/vdirsyncer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/vdirsyncer/
COMMENT=	Synchronization tool for vdir
LICENSE=	mit

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

DEPENDS+=	${PYPKGPREFIX}-click>=2.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-icalendar>=3.6:../../time/py-icalendar
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.3.0:../../devel/py-requests-toolbelt

USE_LANGUAGES=	# none
INSTALLATION_DIRS=	share/example/${PKGBASE}
PLIST_SUBST+=	PKGBASE=${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/example.cfg ${DESTDIR}${PREFIX}/share/example/${PKGBASE}/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
