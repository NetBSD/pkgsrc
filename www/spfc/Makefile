# $NetBSD: Makefile,v 1.2 2000/05/09 21:02:35 jwise Exp $

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
MAKE_ENV+=	CLASSPATH=${CLASSPATH}:${PREFIX}/lib/jsdk.jar
WRKSRC=		${WRKDIR}/spfc-0.2.0/src/

do-install:
	${INSTALL_DATA} ${WRKSRC}/../bin/spfc.jar ${PREFIX}/lib/java
	${MKDIR} ${PREFIX}/share/doc/java/spfc
	(cd ${WRKSRC}/../docs ; ${GTAR} pcf - .) | \
		(cd ${PREFIX}/share/doc/java/spfc ; ${GTAR} pxvf -)

.include "../../mk/bsd.pkg.mk"

# This must be after the include of bsd.pkg.mk
CLASSPATH:=${CLASSPATH}:${PREFIX}/lib/java/jsdk.jar:.
