# $NetBSD: Makefile,v 1.1.1.1 2000/01/18 18:05:29 jwise Exp $

DISTNAME=	spfc-0.2.0
CATEGORIES=	www
MASTER_SITES=	http://java.apache.org/spfc/dist/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://java.apache.org/

# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0:../../www/jsdk20

.include "../../mk/bsd.prefs.mk"

USE_JAVA=
USE_GMAKE=
NO_CONFIGURE=
NO_MTREE=
MAKE_ENV+=	CLASSPATH=${CLASSPATH}:${JSDK_HOME}/lib/jsdk.jar
WRKSRC=		${WRKDIR}/spfc-0.2.0/src/

do-install:
	${INSTALL_DATA} ${WRKSRC}/../bin/spfc.jar ${JSDK_HOME}/lib
	${MKDIR} ${JSDK_HOME}/doc/spfc
	(cd ${WRKSRC}/../docs ; ${GTAR} pcf - .) | \
		(cd ${JSDK_HOME}/doc/spfc ; ${GTAR} pxvf -)

.include "../../mk/bsd.pkg.mk"
JSDK_HOME=	${JAVA_HOME}/jsdk
BUILD_DEFS+=	JSDK_HOME
PREFIX:=	${JSDK_HOME}
