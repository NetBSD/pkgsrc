# $NetBSD: Makefile,v 1.11 2000/10/21 22:59:33 wiz Exp $
# STOP!  Don't update this to a later version of this software.
# The JSDK and Apache Jakarta projects have merged, making the
# jakarta-tomcat package the current version of this software.
# This version exists in pkgsrc strictly to support Apache's
# mod_jserv, which will not build with newer (or older) versions.

DISTNAME=	jsdk20-solaris2-sparc
PKGNAME=	jsdk-2.0
CATEGORIES=	www
MASTER_SITES=	# none
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://java.sun.com/products/servlet/index.html

BUILD_DEPENDS+=        ${LOCALBASE}/bin/urlget:../../www/urlget

LICENSE=	sun-jsdk20-license
USE_JAVA=	yes

WRKSRC=		${WRKDIR}/JSDK2.0
BUILD_DEFS+=    JSDK_HOME
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

RESTRICTED=		"Read license before redistributing the Java(tm) Servlet Development Kit"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

TEMPDIR?=	/tmp
TEMPFILE!=echo ${TEMPDIR}/jsdk20.location.$$$$

pre-fetch:
	if [ ! -x ${LOCALBASE}/bin/urlget ]; \
	then \
		${ECHO} '==> Installing urlget to fetch jsdk20' ; \
		${MAKE} ${MAKEFLAGS} install-build-depends ; \
	fi

do-fetch:
	-if [ ! -f ${DISTDIR}/${DISTFILES} ] ; \
	then \
	${LOCALBASE}/bin/urlget -p http://java.sun.com/cgi-bin/download2.cgi \
		referer=http://java.sun.com/products/servlet/download.html \
		protocol="FTP Download" \
		download-name=jsdk20-solaris2-sparc.tar.Z \
		config-file=jsdk20.config \
		platform=solaris2-sparc \
		domain-checked= \
		> ${TEMPFILE} ; \
	${FETCH_CMD} -o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} `${GREP} ftp:// ${TEMPFILE} | \
		${SED} -e 's|.*\(ftp://.*.tar.Z\).*|\1|'` ;\
	fi

do-install:
	${MKDIR} ${PREFIX}/lib/java
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/lib/jsdk.jar ${PREFIX}/lib/java
	${MKDIR} ${PREFIX}/share/doc/java/jsdk20
	cd ${WRKSRC}/doc ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/jsdk20 ; ${GTAR} pvxf - )
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/jsdk20
	${INSTALL_DATA} -c -m 644 ${WRKSRC}/README ${PREFIX}/share/doc/java/jsdk20
	${MKDIR} ${PREFIX}/share/examples/java/jsdk20
	cd ${WRKSRC}/examples ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/examples/java/jsdk20 ; ${GTAR} pvxf - )
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/java/jsdk20

.include "../../mk/bsd.pkg.mk"
