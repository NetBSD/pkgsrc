# $NetBSD: Makefile,v 1.12 2005/05/09 20:37:25 kristerw Exp $
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
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

RESTRICTED=	"License prohibits redistribution on CDROM"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EXTRACT_CMD=	(cd ${WRKDIR} && unzip -x ${DOWNLOADED_DISTFILE}) || ${TRUE}
WRKSRC=		${WRKDIR}

CSFILES=	cs/images/Logo2.gif \
		cs/images/Logo.gif \
		stage/cs.jar \
		stage/readme.txt \
		stage/jhbasic.jar \
		stage/license.txt \
		stage/CsHelp.jar

post-extract:
	(cd ${WRKDIR} && unzip -x InstallerData/Installer.zip) || ${TRUE}

do-build:
	${SED} -e s,@PREFIX@,${PREFIX},g < ${FILESDIR}/csched.sh > ${WRKDIR}/csched.tmp
	${SED} -e s,@LOCALBASE@,${LOCALBASE},g < ${WRKDIR}/csched.tmp > ${WRKDIR}/csched.tmp2
	${SED} -e s,@JAVA_HOME@,${PKG_JAVA_HOME},g < ${WRKDIR}/csched.tmp2 > ${WRKDIR}/csched

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/cardboard-schedule
	@(cd ${WRKDIR}/C:/projects && ${GTAR} cf - ${CSFILES} | (cd ${PREFIX}/lib/cardboard-schedule && ${GTAR} xvf -))
	${INSTALL_SCRIPT} ${WRKDIR}/csched ${PREFIX}/bin

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
