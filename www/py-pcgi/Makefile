# $NetBSD: Makefile,v 1.8 2003/07/17 22:56:00 grant Exp $
#

DISTNAME=	Zope-2.2.2-src
PKGNAME=	py-pcgi-2.2.2
WRKSRC=		${WRKDIR}/${DISTNAME}/pcgi
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/jbauer/persistcgi/
COMMENT=	Persistent CGI system for Zope and other ZPublisher applications

HAS_CONFIGURE=	yes
EXTRACT_ELEMENTS=	${DISTNAME}/pcgi

ALL_TARGET=	all

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

.include "../../lang/python20/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
