# $NetBSD: Makefile,v 1.1.1.1 2000/01/14 17:20:19 jwise Exp $
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

USE_JAVA=	yes

WRKSRC=		${WRKDIR}/JSDK2.0
BUILD_DEFS+=    JSDK_HOME
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=
NO_MTREE=

.include "../../mk/bsd.prefs.mk"

JSDK_HOME?=	${JAVA_HOME}/jsdk

do-fetch:
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	    ${ECHO_MSG} "==============================================================="; \
	    ${ECHO_MSG} "    For licensing reasons, the JSDK 2.0 distribution must be"; \
	    ${ECHO_MSG} "    fetched manually into \"${DISTDIR}/${DIST_SUBDIR}\" from"; \
	    ${ECHO_MSG} "    http://java.sun.com/products/servlet/download.html"; \
	    ${ECHO_MSG} "==============================================================="; \
	    ${FALSE}; \
	fi

do-install:
	${MKDIR} ${JSDK_HOME}
	cd ${WRKSRC} ; ${GTAR} pcf - . | ( cd ${JSDK_HOME} ; ${GTAR} pvxf - )

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX:=        ${JSDK_HOME}
