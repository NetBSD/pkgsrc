# $NetBSD: Makefile,v 1.18 2006/02/05 00:13:19 rillig Exp $
#

DISTNAME=	cs113ins
PKGNAME=	cardboard-schedule-1.13
CATEGORIES=	time x11
MASTER_SITES=	http://cardboard.nu/downloads/
EXTRACT_SUFX=	.exe

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://cardboard.nu/downloads/
COMMENT=	Project and resource management software implemented in Java/Swing

USE_X11BASE=	yes

RESTRICTED=	License prohibits redistribution on CDROM
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	gtar unzip

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	cd ${WRKDIR:Q} && {					\
			${UNZIP_CMD} -x ${DOWNLOADED_DISTFILE}		\
			|| ${TEST} -f InstallerData/Installer.zip;	\
		}
NO_BUILD=	yes

CSFILES=	cs/images/Logo2.gif \
		cs/images/Logo.gif \
		stage/cs.jar \
		stage/readme.txt \
		stage/jhbasic.jar \
		stage/license.txt \
		stage/CsHelp.jar

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		cs
SUBST_STAGE.cs=		do-configure
SUBST_FILES.cs=		csched.sh
SUBST_SED.cs+=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.cs+=		-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_SED.cs+=		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'

post-extract:
	cd ${WRKDIR} && ${UNZIP_CMD} -x InstallerData/Installer.zip
	${CP} ${FILESDIR:Q}/csched.sh ${WRKDIR:Q}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/lib/cardboard-schedule
	cd ${WRKDIR:Q}/C:/projects && ${PAX} -rw ${CSFILES} ${PREFIX:Q}/lib/cardboard-schedule
	${INSTALL_SCRIPT} ${WRKDIR:Q}/csched.sh ${PREFIX:Q}/bin/csched

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
