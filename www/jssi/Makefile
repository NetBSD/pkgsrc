# $NetBSD: Makefile,v 1.3 2000/05/09 20:53:18 jwise Exp $

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
MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-build:
	(cd ${WRKSRC}/../../docs && CLASSPATH=${CLASSPATH} ${SH} generate_javadoc)
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

do-install:
	${INSTALL_DATA} ${WRKSRC}/ApacheJSSI.jar ${PREFIX}/lib/java/ApacheJSSI.jar
	${MKDIR} ${PREFIX}/share/doc/java/jssi
	(cd ${WRKSRC}/../../docs ; ${GTAR} pcf - .) | \
		(cd ${PREFIX}/share/doc/java/jssi ; ${GTAR} pxvf -)

.include "../../mk/bsd.pkg.mk"

# This must be after bsd.pkg.mk is brought in
CLASSPATH:=${CLASSPATH}:${PREFIX}/lib/java/jsdk.jar:.
