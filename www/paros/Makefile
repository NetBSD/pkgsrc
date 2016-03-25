# $NetBSD: Makefile,v 1.16 2016/03/25 21:03:09 joerg Exp $
#

DISTNAME=	paros-3.2.13-unix
PKGNAME=	${DISTNAME:S/-unix//}
PKGREVISION=	1
CATEGORIES=	www security java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paros/}
EXTRACT_SUFX=	.zip

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.parosproxy.org/
COMMENT=	HTTP/HTTPS proxy for assessing web application vulnerabilities

NO_BUILD=	yes
USE_JAVA2=	yes
USE_JAVA=	run
USE_TOOLS+=	pax

INSTALLATION_DIRS=	bin lib

WRKSRC=		${WRKDIR}/${PKGBASE}

# contains Linux/Windows binaries
CHECK_SHLIBS_SKIP=	lib/paros/libmozembed-linux-gtk1.2.so
CHECK_SHLIBS_SKIP+=	lib/paros/libmozembed-linux-gtk2.so

SUBST_CLASSES+=		java
SUBST_MESSAGE.java=	Fixing hardcoded path to Java.
SUBST_STAGE.java=	pre-configure
SUBST_FILES.java=	${WRKSRC}/startserver.sh
SUBST_SED.java=		-e 's,java ,${PKG_JAVA_HOME}/bin/&,'

do-configure:
	@(${ECHO} '#! /bin/sh' && 			\
		${ECHO} cd ${PREFIX}/lib/${PKGBASE} &&	\
		${CAT} ${WRKSRC}/startserver.sh &&	\
		${ECHO}) > ${WRKDIR}/paros.sh

do-install:
	@cd ${WRKDIR} && pax -rw -pm ${PKGBASE} ${DESTDIR}${PREFIX}/lib/
	${INSTALL_SCRIPT} ${WRKDIR}/paros.sh ${DESTDIR}${PREFIX}/bin/paros

CHECK_SHLIBS_SKIP+=	lib/paros/libjdic.so lib/paros/libtray.so

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
