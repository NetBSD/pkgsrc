# $NetBSD: Makefile,v 1.10 2000/10/21 23:08:07 wiz Exp $

DISTNAME=	swing1_1_1
PKGNAME=	swing-1.1.1
CATEGORIES=	devel x11
MASTER_SITES=	# none
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.javasoft.com/products/jfc/

BUILD_DEPENDS+=        ${LOCALBASE}/bin/urlget:../../www/urlget

RESTRICTED=	"Read license before redistributing the Java(tm) Foundation Classes"
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

LICENSE=	sun-swing-license

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

.include "../../mk/bsd.prefs.mk"

TEMPDIR?=	/tmp
TEMPFILE!=echo ${TEMPDIR}/swing.location.$$$$

pre-fetch:
	if [ ! -x ${LOCALBASE}/bin/urlget ]; \
	then \
		${ECHO} '==> Installing urlget to fetch swing' ; \
		${MAKE} ${MAKEFLAGS} install-build-depends ; \
	fi

do-fetch:
	-if [ ! -f ${DISTDIR}/${DISTFILES} ] ; then \
	${LOCALBASE}/bin/urlget -p http://www.javasoft.com/Download3 \
		referer=http://www.javasoft.com/products/jfc/download.html \
		protocol="FTP Download" \
		download-name=swing1_1_1.zip \
		config-file=swing111.config \
		platform=zip \
		domain-checked= \
		> ${TEMPFILE} ; \
	${FETCH_CMD} -o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} `${GREP} ftp:// ${TEMPFILE} | \
		${SED} -e 's|.*\(ftp://.*.zip\).*|\1|'` ; \
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
