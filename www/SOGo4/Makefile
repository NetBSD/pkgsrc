# $NetBSD: Makefile,v 1.13 2021/07/03 21:00:31 manu Exp $
#

DISTNAME=	SOGo-4.0.8
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	http://www.sogo.nu/files/downloads/SOGo/Sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sogo.nu/
COMMENT=	Groupware server supporting CalDAV, CardDAV and GroupDAV
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_TOOLS+=	bash gmake zip:run

CONFIG_SHELL=	bash
CONFIGURE_ARGS=	--enable-debug --disable-strip
MAKE_JOBS_SAFE=	no

SOGOUSER?=	sogo
SOGOGROUP?=	sogo
SOGOETCDIR?=	${PKG_SYSCONFDIR}
SOGORUNDIR?=	${VARBASE}/sogo

INSTALLATION_DIRS+=	share/examples/SOGo

CONF_FILES+=		share/examples/SOGo/sogo-conf.sh \
			${PKG_SYSCONFDIR}/sogo-conf.sh
CONF_FILES+=		share/examples/SOGo/SOGo.conf \
			${PKG_SYSCONFDIR}/SOGo.conf
OWN_DIRS+=		${SOGOETCDIR}
OWN_DIRS+=		${SOGORUNDIR}
OWN_DIRS_PERMS+=	${SOGOETCDIR} ${SOGOUSER} ${SOGOGROUP} 0755
OWN_DIRS_PERMS+=	${SOGORUNDIR} ${SOGOUSER} ${SOGOGROUP} 0755
BUILD_DEFS+=		VARBASE

PKG_GROUPS+=		${SOGOGROUP}
PKG_USERS+=		${SOGOUSER}:${SOGOGROUP}
PKG_HOME.${SOGOUSER}=	${SOGOETCDIR}
PKG_SHELL.${SOGOUSER}=	${SH}
PKG_GECOS.${SOGOUSER}=	SOGo daemon user

PKG_SYSCONFSUBDIR=	sogo

FILES_SUBST+=	SOGORUNDIR=${SOGORUNDIR}
FILES_SUBST+=	SOGOETCDIR=${SOGOETCDIR}
FILES_SUBST+=	SOGOUSER=${SOGOUSER}
RCD_SCRIPTS=	sogod

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	SoObjects/SOGo/SOGoSystemDefaults.m
SUBST_SED.paths=	-e 's,/etc/sogo/,${PKG_SYSCONFDIR}/,g'

BUILDLINK_TRANSFORM.SunOS+=	rm:-pie

FIX_PERMS= \
	SoObjects/Mailer/SOGoMailLithuanianForward.wo/SOGoMailLithuanianForward.html \
	SoObjects/Mailer/SOGoMailLithuanianForward.wo/SOGoMailLithuanianForward.wod \
	SoObjects/Mailer/SOGoMailLithuanianReply.wo/SOGoMailLithuanianReply.html \
	SoObjects/Mailer/SOGoMailLithuanianReply.wo/SOGoMailLithuanianReply.wod \
	UI/MainUI/MainUI.SOGo/Resources/Slovenian.lproj/Locale \
	UI/Templates/SOGoACLLithuanianAdditionAdvisory.wox \
	UI/Templates/SOGoACLLithuanianModificationAdvisory.wox \
	UI/Templates/SOGoACLLithuanianRemovalAdvisory.wox \
	UI/Templates/SOGoFolderLithuanianAdditionAdvisory.wox \
	UI/Templates/SOGoFolderLithuanianRemovalAdvisory.wox \
	UI/WebServerResources/css/icons.css

# Binary files embed compiler command invoked, which includes 
# harmless build directory references.
CHECK_WRKREF_SKIP+=lib/GNUstep/Frameworks/SOGo.framework/Versions/4/sogo/SOGo
CHECK_WRKREF_SKIP+=lib/GNUstep/Frameworks/SOGo.framework/Versions/4/sogo/libSOGo.so
CHECK_WRKREF_SKIP+=lib/GNUstep/Frameworks/SOGo.framework/Versions/4/sogo/libSOGo.so.4.0.8
CHECK_WRKREF_SKIP+=lib/GNUstep/Frameworks/SOGo.framework/sogo/SOGo
CHECK_WRKREF_SKIP+=lib/GNUstep/Frameworks/SOGo.framework/sogo/libSOGo.so
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/AdministrationUI.SOGo/AdministrationUI
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/Appointments.SOGo/Appointments
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/CommonUI.SOGo/CommonUI
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/Contacts.SOGo/Contacts
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/ContactsUI.SOGo/ContactsUI
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/MailPartViewers.SOGo/MailPartViewers
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/Mailer.SOGo/Mailer
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/MailerUI.SOGo/MailerUI
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/MainUI.SOGo/MainUI
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/PreferencesUI.SOGo/PreferencesUI
CHECK_WRKREF_SKIP+=lib/GNUstep/SOGo/SchedulerUI.SOGo/SchedulerUI
CHECK_WRKREF_SKIP+=lib/GNUstep/SaxDrivers-4.9/versitCardsSaxDriver.sax/versitCardsSaxDriver
CHECK_WRKREF_SKIP+=lib/GNUstep/WOxElemBuilders-4.9/SOGoElements.wox/SOGoElements
CHECK_WRKREF_SKIP+=lib/sogo/libGDLContentStore.so
CHECK_WRKREF_SKIP+=lib/sogo/libGDLContentStore.so.4.9.0
CHECK_WRKREF_SKIP+=lib/sogo/libNGCards.so
CHECK_WRKREF_SKIP+=lib/sogo/libNGCards.so.4.9.0
CHECK_WRKREF_SKIP+=lib/sogo/libSOGo.so
CHECK_WRKREF_SKIP+=lib/sogo/libSOGo.so.4.0.8
CHECK_WRKREF_SKIP+=lib/sogo/libSOGoUI.so
CHECK_WRKREF_SKIP+=lib/sogo/libSOGoUI.so.4.0.0
CHECK_WRKREF_SKIP+=sbin/sogo-ealarms-notify
CHECK_WRKREF_SKIP+=sbin/sogo-slapd-sockd
CHECK_WRKREF_SKIP+=sbin/sogo-tool
CHECK_WRKREF_SKIP+=sbin/sogod

pre-install:
.for f in ${FIX_PERMS}
	${CHMOD} ${NONBINMODE} ${WRKSRC}/${f}
.endfor


post-install:
	${SED} -e "s|@SOGOUSER@|${SOGOUSER}|" ${FILESDIR}/sogo-conf.sh > \
	  ${DESTDIR}${PREFIX}/share/examples/SOGo/sogo-conf.sh
	${SED} -e "s|/usr/GNUstep/System/Library|${PREFIX}/lib/GNUstep|" \
	  ${WRKSRC}/Apache/SOGo.conf > \
	  ${DESTDIR}${PREFIX}/share/examples/SOGo/SOGo.conf
	${SED} -e "s|@PREFIX@|${PREFIX}|" ${FILESDIR}/SOGo.conf >> \
	  ${DESTDIR}${PREFIX}/share/examples/SOGo/SOGo.conf

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/SOPE4/buildlink3.mk"
.include "../../devel/libmemcached/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"


.include "../../mk/bsd.pkg.mk"
