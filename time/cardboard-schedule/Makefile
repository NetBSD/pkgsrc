# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:25 wiz Exp $
#

DISTNAME=	cs113ins
PKGNAME=	cardboard-schedule-1.13
CATEGORIES=	time x11
MASTER_SITES=	http://cardboard.nu/downloads/
EXTRACT_SUFX=	.exe

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://cardboard.nu/download.shtml

USE_JAVA=	yes
USE_X11BASE=	yes
DEPENDS+=	unzip-*:../../archivers/unzip
DEPENDS+=	swing-*:../../x11/swing

RESTRICTED=	"License prohibits redistribution on CDROM"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EXTRACT_CMD=	(cd ${WRKDIR} && unzip -x ${DOWNLOADED_DISTFILE}) || ${TRUE}
MESSAGE_FILE=	${WRKDIR}/MESSAGE

CSFILES=	cs/images/Logo2.gif \
		cs/images/Logo.gif \
		stage/cs.jar \
		stage/readme.txt \
		stage/jhbasic.jar \
		stage/license.txt \
		stage/CsHelp.jar

post-extract:
		(cd ${WRKDIR} && unzip -x InstallerData/Installer.zip) || ${TRUE}

post-build:
		${SED} -e s,@PREFIX@,${PREFIX},g < ${FILESDIR}/csched.sh > ${WRKDIR}/csched.tmp
		${SED} -e s,@LOCALBASE@,${LOCALBASE},g < ${WRKDIR}/csched.tmp > ${WRKDIR}/csched.tmp2
		${SED} -e s,@JAVA_HOME@,${JAVA_HOME},g < ${WRKDIR}/csched.tmp2 > ${WRKDIR}/csched
		${SED} -e s,@PREFIX@,${PREFIX},g < ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

do-install:
		${MKDIR} ${PREFIX}/lib/cardboard-schedule
		@(cd ${WRKDIR}/C:/projects && ${GTAR} cf - ${CSFILES} | (cd ${PREFIX}/lib/cardboard-schedule && ${GTAR} xvf -))
		${INSTALL_SCRIPT} ${WRKDIR}/csched ${PREFIX}/bin

do-build:

.include "../../mk/bsd.pkg.mk"
