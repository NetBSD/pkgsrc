# $NetBSD: Makefile,v 1.3 2000/08/18 22:46:52 hubertf Exp $

DISTNAME=	swing1_1_1
PKGNAME=	swing-1.1.1
CATEGORIES=	devel x11
MASTER_SITES=	# none
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.javasoft.com/products/jfc/

RESTRICTED=	"Read license before redistributing the Java(tm) Foundation Classes"
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_JAVA=	yes
WRKSRC=		${WRKDIR}/swing-1.1.1fcs
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ROOT_GROUP?=	root
.else
ROOT_GROUP?=	wheel
.endif

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
	${CHOWN} -R root:${ROOT_GROUP} ${PREFIX}/share/doc/java/swing \
		${PREFIX}/share/examples/java/swing

.include "../../mk/bsd.pkg.mk"
