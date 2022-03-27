# $NetBSD: Makefile,v 1.19 2022/03/27 10:29:40 nia Exp $

DISTNAME=	paros-3.2.13-unix
PKGNAME=	${DISTNAME:S/-unix//}
PKGREVISION=	1
CATEGORIES=	www security java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paros/}
EXTRACT_SUFX=	.zip

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/paros/
COMMENT=	HTTP/HTTPS proxy for assessing web application vulnerabilities
LICENSE=	artistic

NO_BUILD=	yes
USE_JAVA2=	yes
USE_JAVA=	run
USE_TOOLS+=	pax

INSTALLATION_DIRS=	bin lib

WRKSRC=		${WRKDIR}/${PKGBASE}

# contains Linux/Windows binaries
CHECK_SHLIBS_SKIP=	lib/paros/libmozembed-linux-gtk1.2.so
CHECK_SHLIBS_SKIP+=	lib/paros/libmozembed-linux-gtk2.so
CHECK_SHLIBS_SKIP+=	lib/paros/libjdic.so lib/paros/libtray.so
CHECK_SSP_SKIP+=	${CHECK_SHLIBS_SKIP}
CHECK_MKPIE_SUPPORTED=	no
CHECK_RELRO_SUPPORTED=	no

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

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
