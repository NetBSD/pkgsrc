# $NetBSD: Makefile,v 1.75 2023/11/08 13:21:15 wiz Exp $
#

DISTNAME=	SOGo-2.3.23
PKGREVISION=	29
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

FIX_PERMS= \
	SoObjects/Mailer/SOGoMailLithuanianForward.wo/SOGoMailLithuanianForward.html \
	SoObjects/Mailer/SOGoMailLithuanianForward.wo/SOGoMailLithuanianForward.wod \
	SoObjects/Mailer/SOGoMailLithuanianReply.wo/SOGoMailLithuanianReply.html \
	SoObjects/Mailer/SOGoMailLithuanianReply.wo/SOGoMailLithuanianReply.wod \
	UI/Templates/SOGoACLLithuanianAdditionAdvisory.wox \
	UI/Templates/SOGoACLLithuanianModificationAdvisory.wox \
	UI/Templates/SOGoACLLithuanianRemovalAdvisory.wox \
	UI/Templates/SOGoFolderLithuanianAdditionAdvisory.wox \
	UI/Templates/SOGoFolderLithuanianRemovalAdvisory.wox

pre-configure:
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
	${MKDIR} -p ${DESTDIR}${PREFIX}/lib/GNUstep/Frameworks
	${LN} -s ../SOGo/SOGo.framework \
	  ${DESTDIR}${PREFIX}/lib/GNUstep/Frameworks/SOGo.framework

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/SOPE/buildlink3.mk"
.include "../../devel/libmemcached/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"


.include "../../mk/bsd.pkg.mk"
