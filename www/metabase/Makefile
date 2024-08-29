# $NetBSD: Makefile,v 1.1 2024/08/29 15:00:26 ryoon Exp $

DISTNAME=	metabase
PKGNAME=	${DISTNAME}-0.50.22
CATEGORIES=	www
MASTER_SITES=	https://downloads.metabase.com/v${PKGVERSION_NOREV:S/rc/-RC/}/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.jar

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.metabase.com/
COMMENT=	Business intelligence and analytics web application
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}

NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_JAVA=	run
USE_JAVA2=	11

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE

METABASE_USER?=		metabase
METABASE_GROUP?=	metabase
PKG_GROUPS=		${METABASE_GROUP}
PKG_USERS=		${METABASE_USER}:${METABASE_GROUP}
PKG_GROUPS_VARS+=	METABASE_GROUP
PKG_USERS_VARS+=	METABASE_USER
PKG_HOME.metabase=	${METABASE_HOME}
PKG_SHELL.metabase=	${SH}

PKG_SYSCONFDIR.metabase=	${METABASE_HOME}/conf
OWN_DIRS_PERMS+=		${PKG_SYSCONFDIR.metabase} ${METABASE_USER} ${METABASE_GROUP} 0755

EGDIR=			${METABASE_HOME}/examples
CONF_FILES_PERMS+=	${EGDIR}/log4j2.xml ${PKG_SYSCONFDIR.metabase}/log4j2.xml \
			${METABASE_USER} ${METABASE_GROUP} 0640

OWN_DIRS_PERMS+=	${VARBASE}/log/metabase ${METABASE_USER} ${METABASE_GROUP} 0755

RCD_SCRIPTS=	metabase
METABASE_HOME=	${PREFIX}/share/metabase
FILES_SUBST+=	METABASE_HOME=${METABASE_HOME}
FILES_SUBST+=	JAVA_HOME=${PKG_JAVA_HOME}
FILES_SUBST+=	METABASE_USER=${METABASE_USER}

SUBST_CLASSES+=		var
SUBST_STAGE.var=	pre-configure
SUBST_MESSAGE.var=	Setting VARBASE
SUBST_FILES.var=	log4j2.xml
SUBST_VARS.var=		VARBASE

INSTALLATION_DIRS+=	${METABASE_HOME}/examples

pre-patch:
	${INSTALL_DATA} ${FILESDIR}/log4j2.xml \
		${WRKSRC}/log4j2.xml

do-install:
	${INSTALL_DATA} ${WRKSRC}/metabase.jar \
		${DESTDIR}${METABASE_HOME}
	${INSTALL_DATA} ${WRKSRC}/log4j2.xml \
		${DESTDIR}${METABASE_HOME}/examples

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
