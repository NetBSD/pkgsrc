# $NetBSD: Makefile,v 1.4 1999/10/28 14:29:20 agc Exp $
#

DISTNAME=	t1lib-0.9.2
CATEGORIES=	textproc devel graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE:=libs/graphics/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.neuroinformatik.ruhr-uni-bochum.de/ini/PEOPLE/rmz/t1lib.html

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes

WRKSRC=		${WRKDIR}/T1-0.9.2
MESSAGE_FILE=	${WRKDIR}/MESSAGE
ALL_TARGET=	without_doc

post-build:
	${SED} -e 's|@@PREFIX@@|${PREFIX}|g' < ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

post-install:
	${MKDIR} ${PREFIX}/share/t1lib
	cd ${WRKSRC}; \
	  ${PAX} -r -w Fonts ${PREFIX}/share/t1lib; \
	  ${PAX} -r -w -s "/doc/t1lib/" doc ${PREFIX}/share/doc
	${MKDIR} ${PREFIX}/share/examples/t1lib
	cd ${WRKSRC}/examples; \
	  ${PAX} -r -w FontDataBase README.t1example1 t1example1.c t1lib.config \
	      ${PREFIX}/share/examples/t1lib
	${SED} -e 's|@@X11BASE@@|${X11BASE}|g' -e 's|@@LOCALBASE@@|${LOCALBASE}|g' \
	    -e 's|@@PREFIX@@|${PREFIX}|g' < ${FILESDIR}/t1lib.config.netbsd \
	    > ${PREFIX}/share/examples/t1lib/t1lib.config.netbsd
	if [ ! -f ${PREFIX}/share/t1lib/t1lib.config ]; then \
	  ${CP} ${PREFIX}/share/examples/t1lib/t1lib.config.netbsd \
	      ${PREFIX}/share/t1lib/t1lib.config; \
	fi
	if [ ! -f ${PREFIX}/share/t1lib/FontDataBase ]; then \
	  ${CP} ${PREFIX}/share/examples/t1lib/FontDataBase ${PREFIX}/share/t1lib; \
	fi

.include "../../mk/bsd.pkg.mk"
