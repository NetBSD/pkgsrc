# $NetBSD: Makefile,v 1.5 2001/01/29 11:34:46 wiz Exp $

DISTNAME=	ApacheJSSI-1.1.2
PKGNAME=	jssi-1.1.2
CATEGORIES=	www
MASTER_SITES=	http://java.apache.org/jservssi/dist/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://java.apache.org/

# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0:../../www/jsdk20

.include "../../mk/bsd.prefs.mk"

USE_JAVA=
USE_GMAKE=
NO_CONFIGURE=
WRKSRC=		${WRKDIR}/ApacheJSSI-1.1.2/src/java
MAKE_ENV+=	CLASSPATH=${CLASSPATH}

post-build:
	(cd ${WRKSRC}/../../docs && CLASSPATH=${CLASSPATH} ${SH} generate_javadoc)

do-install:
	${INSTALL_DATA} ${WRKSRC}/ApacheJSSI.jar ${PREFIX}/lib/java/ApacheJSSI.jar
	${MKDIR} ${PREFIX}/share/doc/java/jssi
	(cd ${WRKSRC}/../../docs ; ${GTAR} pcf - .) | \
		(cd ${PREFIX}/share/doc/java/jssi ; ${GTAR} pxvf -)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/jssi

.include "../../mk/bsd.pkg.mk"

# This must be after bsd.pkg.mk is brought in
CLASSPATH:=${CLASSPATH}:${PREFIX}/lib/java/jsdk.jar:.
