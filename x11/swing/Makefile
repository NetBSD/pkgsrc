# $NetBSD: Makefile,v 1.16 2001/11/14 14:47:57 agc Exp $

DISTNAME=	swing1_1_1
PKGNAME=	swing-1.1.1
CATEGORIES=	devel x11
MASTER_SITES=	# none
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.javasoft.com/products/jfc/
COMMENT=	Sun's Java Foundation Classes (the Swing UI toolkit), version 1.1.1

BUILD_DEPENDS+=        urlget>=1.3:../../www/urlget

RESTRICTED=	"Read license before redistributing the Java(tm) Foundation Classes"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
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
TEMPFILE!=	echo ${TEMPDIR}/swing.location.$$$$
URLGET?=	${LOCALBASE}/bin/urlget

pre-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then	\
		if [ ! -x ${URLGET} ]; then				\
			${MAKE} install-depends DEPENDS=;		\
		fi;							\
	fi

do-fetch:
	-@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ] ; then	\
		${URLGET} -p http://java.sun.com/Download3		\
			referer=					\
			protocol="FTP Download"				\
			download-name=${DISTNAME}${EXTRACT_SUFX}	\
			config-file=swing111.config			\
			platform=zip					\
			domain-checked=					\
			> ${TEMPFILE};					\
		${FETCH_CMD} -o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}	\
			`${GREP} ftp:// ${TEMPFILE} |			\
			${SED} -e 's|.*\(ftp://.*.zip\).*|\1|'`;	\
	fi

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/swingall.jar ${PREFIX}/lib/java
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/beaninfo.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/mac.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/motif.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/multi.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/swing.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/windows.jar ${PREFIX}/lib/java/swing
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/swing
	cd ${WRKSRC}/doc && ${PAX} -rwpe . ${PREFIX}/share/doc/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/CHANGES.txt ${PREFIX}/share/doc/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/LICENSE.txt ${PREFIX}/share/doc/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/README.html ${PREFIX}/share/doc/java/swing
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/README.txt ${PREFIX}/share/doc/java/swing
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/swing
	cd ${WRKSRC}/examples && ${PAX} -rwpe . ${PREFIX}/share/examples/java/swing
	${CHOWN} -R root:${ROOT_GROUP} ${PREFIX}/share/doc/java/swing \
		${PREFIX}/share/examples/java/swing

.include "../../mk/bsd.pkg.mk"
