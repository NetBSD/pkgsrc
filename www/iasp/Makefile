# $NetBSD: Makefile,v 1.1.1.1 2003/01/01 07:03:40 jlam Exp $

.include "../iasp/Makefile.common"

PKGNAME=	iasp-${IASP_VERSION}
COMMENT=	Instant ASP: Java implementation of Active Server Pages

WRKSRC=		${WRKDIR}/${IASP_DIR}

SCRIPTS_ENV+=	CAT=${CAT:Q}
SCRIPTS_ENV+=	ECHO=${ECHO:Q}
SCRIPTS_ENV+=	SED=${SED:Q}
SCRIPTS_ENV+=	SH=${SH:Q}
SCRIPTS_ENV+=	IASP=${IASP_DESTDIR}
FILES_SUBST=	IASP=${IASP_DESTDIR}
PLIST_SUBST=	IASP=${IASP_DESTDIR:S/^${PREFIX}\///}

OWN_DIRS=	${IASP_DESTDIR} ${IASP_DESTDIR}/logs
CONFDIR=	${IASP_DESTDIR}/properties
SFILES=		cdonts.properties	dbserver.properties
SFILES+=	ejb.properties		loadbalance.properties
SFILES+=	msmq.properties		rules.properties
SFILES+=	security.properties	server.properties
SFILES+=	servlets.properties
SUPPORT_FILES=	# empty
.for FILE in ${SFILES}
SUPPORT_FILES+=	${CONFDIR}/${FILE}.default ${CONFDIR}/${FILE}
.endfor
SUPPORT_FILES+=	/dev/null ${IASP_DESTDIR}/properties/license
RCD_SCRIPTS=	iasp iasp_admin

post-extract:
	cd ${WRKDIR}; ${GTAR} -xf ${IASP_TARFILE}
	cd ${WRKSRC}; ${RM} -rf bin logs
	cd ${WRKSRC}; ${RM} -f properties/license
	cd ${WRKSRC}; for file in properties/*.properties; do		\
		${MV} -f $$file $$file.default;				\
	done

do-build:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/gen-scripts.sh
	${MKDIR} ${WRKSRC}/WEB-INF
	${CP} ${FILESDIR}/web.xml ${WRKSRC}/WEB-INF
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mod_iasp.conf		\
		> ${WRKSRC}/mod_iasp.conf

do-install:
	${MKDIR} ${IASP_DESTDIR:H}
	cd ${WRKDIR}; ${CP} -R ${IASP_DIR} ${IASP_DESTDIR:H}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
