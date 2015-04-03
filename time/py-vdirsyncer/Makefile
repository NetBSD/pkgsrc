# $NetBSD: Makefile,v 1.18 2015/04/03 07:34:15 wiz Exp $

DISTNAME=	vdirsyncer-0.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	https://pypi.python.org/packages/source/v/vdirsyncer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/vdirsyncer/
COMMENT=	Synchronization tool for vdir
LICENSE=	mit

EXTRACT_USING=	bsdtar	# gtar cannot handle pre-1970 timestamps

DEPENDS+=	${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-click>=2.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.3.0:../../devel/py-requests-toolbelt
# optional, but recommended
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring

USE_LANGUAGES=	# none
INSTALLATION_DIRS=	share/examples/${PKGBASE}
PLIST_SUBST+=	PKGBASE=${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/example.cfg ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
