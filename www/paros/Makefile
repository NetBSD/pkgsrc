# $NetBSD: Makefile,v 1.1.1.1 2006/01/11 18:59:36 salo Exp $
#

DISTNAME=	paros-3.2.8-unix
PKGNAME=	${DISTNAME:S/-unix//}
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paros/}
EXTRACT_SUFX=	.zip

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.parosproxy.org/
COMMENT=	HTTP/HTTPS proxy for assessing web application vulnerabilities

NO_BUILD=	yes
USE_JAVA2=	yes
USE_JAVA=	run

WRKSRC=		${WRKDIR}/${PKGBASE}

SUBST_CLASSES+=		java
SUBST_MESSAGE.java=	"Fixing hardcoded path to Java."
SUBST_STAGE.java=	pre-configure
SUBST_FILES.java=	${WRKSRC}/startserver.sh
SUBST_SED.java=		-e 's,^java,${PKG_JAVA_HOME}/bin/&,'

do-configure:
	@(${ECHO} '#! /bin/sh' && 			\
		${ECHO} cd ${PREFIX}/lib/${PKGBASE} &&	\
		${CAT} ${WRKSRC}/startserver.sh &&	\
		${ECHO}) > ${WRKDIR}/paros.sh
do-install:
	@cd ${WRKDIR} && ${PAX} -rw -pm ${PKGBASE} ${PREFIX}/lib/
	${INSTALL_SCRIPT} ${WRKDIR}/paros.sh ${PREFIX}/bin/paros

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
