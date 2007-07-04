# $NetBSD: Makefile,v 1.15 2007/07/04 20:55:05 jlam Exp $

.include "../../www/iasp/Makefile.common"

PKGNAME=	iasp-${IASP_VERSION}
PKGREVISION=	4
COMMENT=	Instant ASP: Java implementation of Active Server Pages

USE_TOOLS+=	gtar

SCRIPTS_ENV+=	CAT=${CAT:Q}
SCRIPTS_ENV+=	CHMOD=${CHMOD:Q}
SCRIPTS_ENV+=	ECHO=${ECHO:Q}
SCRIPTS_ENV+=	SED=${SED:Q}
SCRIPTS_ENV+=	SH=${SH:Q}
SCRIPTS_ENV+=	IASP=${IASP_DESTDIR}
FILES_SUBST+=	IASP=${IASP_DESTDIR:Q}
PLIST_SUBST+=	IASP=${IASP_DESTDIR:S/^${PREFIX}\///:Q}

IASP_USER?=	${APACHE_USER}
IASP_GROUP?=	${APACHE_GROUP}
FILES_SUBST+=	IASP_USER=${IASP_USER:Q}
FILES_SUBST+=	IASP_GROUP=${IASP_GROUP:Q}

PKG_USERS=	${IASP_USER}:${IASP_GROUP}
PKG_GROUPS=	${IASP_GROUP}

PKG_GROUPS_VARS+=	IASP_GROUP
PKG_USERS_VARS+=	IASP_USER

WRKSRC=		${WRKDIR}/${IASP_DIR}
REQD_DIRS=	${IASP_DESTDIR}
OWN_DIRS_PERMS=	${IASP_DESTDIR}/logs ${IASP_USER} ${IASP_GROUP} 0750
CONFDIR=	${IASP_DESTDIR}/properties
CFILES=		cdonts.properties	dbserver.properties
CFILES+=	ejb.properties		loadbalance.properties
CFILES+=	msmq.properties		rules.properties
CFILES+=	security.properties	server.properties
CFILES+=	servlets.properties
CONF_FILES=	# empty
.for FILE in ${CFILES}
CONF_FILES+=	${CONFDIR}/${FILE}.default ${CONFDIR}/${FILE}
.endfor
CONF_FILES+=	/dev/null ${IASP_DESTDIR}/properties/license
RCD_SCRIPTS=	iasp iasp_admin

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	mod_iasp.conf
SUBST_SED.paths+=	-e 's,@IASP@,${IASP_DESTDIR},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	cd ${WRKDIR}; ${GTAR} -xf ${IASP_TARFILE}
	cd ${WRKSRC}; ${RM} -rf bin logs
	cd ${WRKSRC}; ${RM} -f properties/license
	cd ${WRKSRC}; for file in properties/*.properties; do		\
		${MV} -f $$file $$file.default;				\
	done
	${CP} ${FILESDIR}/mod_iasp.conf ${WRKSRC}

do-build:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/gen-scripts.sh
	${MKDIR} ${WRKSRC}/WEB-INF
	${CP} ${FILESDIR}/web.xml ${WRKSRC}/WEB-INF

do-install:
	${INSTALL_DATA_DIR} ${IASP_DESTDIR:H}
	cd ${WRKDIR}; ${CP} -R ${IASP_DIR} ${IASP_DESTDIR:H}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
