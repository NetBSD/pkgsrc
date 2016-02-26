# $NetBSD: Makefile,v 1.7 2016/02/26 14:03:22 jperkin Exp $
#

JETTYVER=	7.6.8.v20121106
DISTNAME=	jetty-distribution-${JETTYVER}
PKGNAME=	${DISTNAME:S/distribution-//:S/.v/./}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.eclipse.org/jetty/${JETTYVER}/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jetty.codehaus.org/jetty/
COMMENT=	Jetty is a Java HTTP Server and Servlet Container
LICENSE=	apache-2.0 OR epl-v1.0

USE_LANGUAGES=	# none

NO_BUILD=	yes

USE_TOOLS+=	bash:run pax
USE_JAVA=	run
USE_JAVA2=	6

.include "../../mk/bsd.prefs.mk"

JETTY_HOME=		${PREFIX}/share/jetty
EGDIR=			${PREFIX}/share/examples/jetty
RCD_SCRIPTS=		jetty
JETTY_USER?=		jetty
JETTY_GROUP?=		jetty
USERGROUP_PHASE=	pre-install
PKG_GROUPS=		${JETTY_GROUP}
PKG_USERS=		${JETTY_USER}:${JETTY_GROUP}
PKG_GROUPS_VARS+=	JETTY_GROUP
PKG_USERS_VARS=		JETTY_USER
PKG_HOME.jetty=		${JETTY_HOME}
PKG_SHELL.jetty=	${SH}
PKG_SYSCONFDIR.jetty=	${JETTY_HOME}/etc
OWN_DIRS+=		${PKG_SYSCONFDIR.jetty}
FILES_SUBST+=		JAVA_HOME=${PKG_JAVA_HOME} JETTY_HOME=${JETTY_HOME} \
			JETTY_USER=${JETTY_USER} JETTY_GROUP=${JETTY_GROUP} \
			JETTY_PORT=${JETTY_PORT} JETTY_RUN=${JETTY_RUN} \
			JETTY_PID=${JETTY_PID}

INSTALLATION_DIRS=	${JETTY_HOME} ${EGDIR}

CONFS=		README.spnego \
		jdbcRealm.properties \
		jetty-ajp.xml \
		jetty-bio-ssl.xml \
		jetty-bio.xml \
		jetty-contexts.xml \
		jetty-debug.xml \
		jetty-deploy.xml \
		jetty-fileserver.xml \
		jetty-ipaccess.xml \
		jetty-jmx.xml \
		jetty-logging.xml \
		jetty-monitor.xml \
		jetty-overlay.xml \
		jetty-plus.xml \
		jetty-policy.xml \
		jetty-proxy.xml \
		jetty-requestlog.xml \
		jetty-rewrite.xml \
		jetty-ssl.xml \
		jetty-stats.xml \
		jetty-testrealm.xml \
		jetty-webapps.xml \
		jetty-xinetd.xml \
		jetty.conf \
		jetty.xml \
		keystore \
		krb5.ini \
		realm.properties \
		spnego.conf \
		spnego.properties \
		webdefault.xml

.for i in ${CONFS}
CONF_FILES+=		${EGDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.endfor

REPLACE_BASH+=	bin/jetty.sh

pre-configure:
	${RM} -r ${WRKSRC}/bin/README.jetty-cygwin.txt.txt \
			 ${WRKSRC}/bin/jetty-xinetd.sh \
			 ${WRKSRC}/bin/jetty-cygwin.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/etc/* ${DESTDIR}${EGDIR}
	${RM} -r ${WRKSRC}/etc
	(cd ${WRKSRC} && ${PAX} -rw -pm . ${DESTDIR}${JETTY_HOME})

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
