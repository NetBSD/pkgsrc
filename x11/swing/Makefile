# $NetBSD: Makefile,v 1.1.1.1 2000/05/25 20:52:12 jwise Exp $

DISTNAME=	swing1_1_1
PKGNAME=	swing-1.1.1
CATEGORIES=	devel x11
MASTER_SITES=	# none
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.javasoft.com/products/jfc/

USE_JAVA=	yes

WRKSRC=		${WRKDIR}/swing-1.1.1fcs
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=
RESTRICTED=	"Read license before redistributing the Java(tm) Foundation Classes"
NO_CDROM=	${RESTRICTED}
MIRROR_DISTFILE=no

.include "../../mk/bsd.prefs.mk"

do-fetch:
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	    ${ECHO_MSG} "==============================================================="; \
	    ${ECHO_MSG} "    For licensing reasons, the Swing 1.1.1 distribution must be"; \
	    ${ECHO_MSG} "    fetched manually into \"${DISTDIR}/${DIST_SUBDIR}\" from"; \
	    ${ECHO_MSG} "    ${HOMEPAGE}download.html "; \
	    ${ECHO_MSG} "==============================================================="; \
	    ${FALSE}; \
	fi

do-install:
	${MKDIR} ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/swingall.jar ${PREFIX}/lib/java
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/beaninfo.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/mac.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/motif.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/multi.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/swing.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/windows.jar ${PREFIX}/lib/java/swing
	${MKDIR} ${PREFIX}/share/doc/java/swing
	cd ${WRKSRC}/doc ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/swing ; ${GTAR} pvxf - )
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/CHANGES.txt ${PREFIX}/share/doc/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/LICENSE.txt ${PREFIX}/share/doc/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/README.html ${PREFIX}/share/doc/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/README.txt ${PREFIX}/share/doc/java/swing
	${MKDIR} ${PREFIX}/share/examples/java/swing
	cd ${WRKSRC}/examples ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/examples/java/swing ; ${GTAR} pvxf - )

.include "../../mk/bsd.pkg.mk"
