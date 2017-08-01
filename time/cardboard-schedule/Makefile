# $NetBSD: Makefile,v 1.31 2017/08/01 17:40:17 wiz Exp $
#

DISTNAME=	cs113ins
PKGNAME=	cardboard-schedule-1.13
PKGREVISION=	1
CATEGORIES=	time x11
MASTER_SITES=	http://cardboard.nu/downloads/
EXTRACT_SUFX=	.exe

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://cardboard.nu/docs/software.html
COMMENT=	Project and resource management software implemented in Java/Swing
LICENSE=	cardboard-schedule-license

RESTRICTED=	Distribution permitted only of unmodified distfile at no charge.
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_TOOLS+=	pax gtar

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
UNZIP_CMD?=	unzip
.else
USE_TOOLS+=	unzip
.endif

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	cd ${WRKDIR:Q} && {					\
			${UNZIP_CMD} $$extract_file		\
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

INSTALLATION_DIRS=	bin lib/cardboard-schedule

SUBST_CLASSES+=		cs
SUBST_STAGE.cs=		do-configure
SUBST_FILES.cs=		csched.sh
SUBST_SED.cs+=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.cs+=		-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_SED.cs+=		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'

post-extract:
	cd ${WRKDIR} && ${UNZIP_CMD} InstallerData/Installer.zip
	${CP} ${FILESDIR:Q}/csched.sh ${WRKDIR:Q}

do-install:
	cd ${WRKDIR}/C:/projects && pax -rw ${CSFILES} ${DESTDIR}${PREFIX}/lib/cardboard-schedule
	${INSTALL_SCRIPT} ${WRKDIR:Q}/csched.sh ${DESTDIR}${PREFIX}/bin/csched

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
