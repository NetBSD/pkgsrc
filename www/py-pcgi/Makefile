# $NetBSD: Makefile,v 1.9 2004/01/20 12:27:59 agc Exp $
#

DISTNAME=	Zope-2.2.2-src
PKGNAME=	py-pcgi-2.2.2
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/jbauer/persistcgi/
COMMENT=	Persistent CGI system for Zope and other ZPublisher applications

WRKSRC=		${WRKDIR}/${DISTNAME}/pcgi
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
