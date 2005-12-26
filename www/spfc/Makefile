# $NetBSD: Makefile,v 1.18 2005/12/26 23:39:35 schmonz Exp $

DISTNAME=	spfc-0.2.0
CATEGORIES=	www java
MASTER_SITES=	http://java.apache.org/spfc/dist/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://java.apache.org/
COMMENT=	Apache.org's Server Page Foundation Classes

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

# yes, this needs _exactly_ version 2.0
DEPENDS+=	jsdk-2.0:../../www/jsdk20

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/spfc-0.2.0/src/
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes
MAKE_ENV+=	CLASSPATH=${CLASSPATH}:${PREFIX}/lib/jsdk.jar

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/../bin/spfc.jar ${PREFIX}/lib/java
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/doc/java/spfc
	cd ${WRKSRC}/../docs && ${PAX} -rw -pp . ${PREFIX}/share/doc/java/spfc

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

# This must be after the include of bsd.pkg.mk
CLASSPATH:=${CLASSPATH}:${PREFIX}/lib/java/jsdk.jar:.
