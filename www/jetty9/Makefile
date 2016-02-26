# $NetBSD: Makefile,v 1.2 2016/02/26 14:03:22 jperkin Exp $

JETTYVER=	9.2.14.v20151106
DISTNAME=	jetty-distribution-${JETTYVER}
PKGNAME=	${DISTNAME:S/distribution-//:S/.v/./}
CATEGORIES=	www
MASTER_SITES=	http://download.eclipse.org/jetty/${JETTYVER}/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eclipse.org/jetty/
COMMENT=	Jetty is a Java HTTP Server and Servlet Container
LICENSE=	apache-2.0 OR epl-v1.0

USE_LANGUAGES=	# none

NO_BUILD=	yes

USE_TOOLS+=	bash:run pax
USE_JAVA=	run
USE_JAVA2=	6

.include "../../mk/bsd.prefs.mk"

JETTY_HOME=		${LOCALBASE}/share/jetty
JETTY_BASE?=		${VARBASE}/jetty
JETTY_LOGS?=		${JETTY_BASE}/logs
JETTY_RUN?=		${JETTY_BASE}

JETTY_USER?=		jetty
JETTY_GROUP?=		jetty
PKG_GROUPS=		${JETTY_GROUP}
PKG_USERS=		${JETTY_USER}:${JETTY_GROUP}
PKG_GROUPS_VARS+=	JETTY_GROUP
PKG_USERS_VARS=		JETTY_USER
PKG_HOME.jetty=		${JETTY_BASE}
PKG_SHELL.jetty=	${SH}

RCD_SCRIPTS=		jetty

FILES_SUBST+=		JAVA_HOME=${PKG_JAVA_HOME} \
			JETTY_HOME=${JETTY_HOME:Q} JETTY_BASE=${JETTY_BASE:Q} \
			JETTY_LOGS=${JETTY_LOGS:Q} JETTY_RUN=${JETTY_RUN:Q} \
			JETTY_USER=${JETTY_USER} JETTY_GROUP=${JETTY_GROUP}

OWN_DIRS=		${JETTY_BASE} ${JETTY_RUN} ${JETTY_LOGS}
OWN_DIRS_PERMS=		${JETTY_BASE} ${JETTY_USER} ${JETTY_GROUP} 0755
OWN_DIRS_PERMS+=	${JETTY_LOGS} ${JETTY_USER} ${JETTY_GROUP} 0755
OWN_DIRS_PERMS+=	${JETTY_RUN} ${JETTY_USER} ${JETTY_GROUP} 0755

BUILD_DEFS+=		VARBASE JETTY_BASE JETTY_LOGS JETTY_RUN

INSTALLATION_DIRS=	${JETTY_HOME}

CONF_FILES+=		${JETTY_HOME}/start-example.ini ${JETTY_BASE}/start.ini

REPLACE_BASH+=		bin/jetty.sh

CHECK_SHLIBS_SKIP+=	share/jetty/lib/setuid/libsetuid-*.so

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pm . ${DESTDIR}${JETTY_HOME}
	${INSTALL_DATA} ${FILESDIR}/start.ini \
	    ${DESTDIR}${JETTY_HOME}/start-example.ini

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
