# $NetBSD: Makefile,v 1.2 2000/07/28 17:23:56 tsarna Exp $
#

DISTNAME=	Zope-2.2.0-src
PKGNAME=	py-pcgi-2.2.0
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://starship.python.net/crew/jbauer/persistcgi/

DEPENDS+=	python-1.5.2:../../lang/python

HAS_CONFIGURE=	yes
SITE_PKG=		lib/python1.5/site-packages
PYTHON_LIBDIR=		${LOCALBASE}/${SITE_PKG}
EXTRACT_ELEMENTS=	${DISTNAME}/pcgi

WRKSRC=		${WRKDIR}/${DISTNAME}/pcgi

post-build:
	(cd ${WRKSRC}; ${LOCALBASE}/bin/python ${PREFIX}/lib/python1.5/compileall.py .)
	(cd ${WRKSRC}; ${LOCALBASE}/bin/python -O ${PREFIX}/lib/python1.5/compileall.py .)
	(cd ${WRKSRC}/Util; \
		${SED} -e s,/usr/local,${PREFIX}, <pcgifile.py >pcgifile; \
		${SED} -e s,/usr/local,${PREFIX}, <killpcgi.py >killpcgi )

do-install:
	${INSTALL_SCRIPT_DIR} ${PYTHON_LIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/pcgi_publisher.py* ${PYTHON_LIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/pcgi-wrapper ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/Util/pcgifile ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/Util/killpcgi ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
