# $NetBSD: Makefile,v 1.4 2000/10/22 20:30:05 tsarna Exp $
#

DISTNAME=	Zope-2.2.2-src
PKGNAME=	py-pcgi-2.2.2
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://starship.python.net/crew/jbauer/persistcgi/

HAS_CONFIGURE=	yes
EXTRACT_ELEMENTS=	${DISTNAME}/pcgi

ALL_TARGET=	all

WRKSRC=		${WRKDIR}/${DISTNAME}/pcgi

post-build:
	(cd ${WRKSRC}; ${PY_PROG} ${PY_LIBDIR}/compileall.py .)
	(cd ${WRKSRC}; ${PY_PROG} -O ${PY_LIBDIR}/compileall.py .)
	(cd ${WRKSRC}/Util; \
		${SED} -e s,/usr/local,${PREFIX}, <pcgifile.py >pcgifile; \
		${SED} -e s,/usr/local,${PREFIX}, <killpcgi.py >killpcgi )

do-install:
	${INSTALL_SCRIPT_DIR} ${PY_SITEPKG}
	${INSTALL_SCRIPT} ${WRKSRC}/pcgi_publisher.py* ${PY_SITEPKG}
	${INSTALL_PROGRAM} ${WRKSRC}/pcgi-wrapper ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/Util/pcgifile ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Util/killpcgi ${PREFIX}/bin

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
