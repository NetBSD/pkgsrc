# $NetBSD: Makefile,v 1.17 2006/01/12 17:37:17 rillig Exp $

DISTNAME=	w3c-httpd-3.0A
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/httpd/ \
		ftp://ftp-eu.w3.org/pub/httpd/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.w3.org/pub/WWW/Daemon/
COMMENT=	WWW server from the W3 Consortium (W3C)

WRKSRC=		${WRKDIR}

SUBST_CLASSES+=		strcasestr
SUBST_STAGE.strcasestr=	post-patch
SUBST_FILES.strcasestr=	Daemon/Implementation/HTWild.c \
	Library/Implementation/HTString.c \
	Library/Implementation/HTString.h \
	Library/Implementation/HTString.h
SUBST_SED.strcasestr=	-e "s,\([[:blank:]]\)\(strcasestr\),\1x\2,g"

EGDIR=			${PREFIX}/share/examples/w3c-httpd
INSTALLATION_DIRS=	bin sbin share/examples/w3c-httpd

.for f in all.conf caching.conf httpd.conf prot.conf proxy.conf
CONF_FILES+=	${EGDIR:Q}/${f:Q}	${PKG_SYSCONFDIR}/${f:Q}
.endfor

pre-configure:
.if !defined(MD5_PW)
	@${ECHO} ""
	@${ECHO} "Defaulting to DES encrypted passwords."
	@${ECHO} "Set the environment variable MD5_PW if you want MD5 encrypted passwords."
	@${ECHO} ""
.else
	@${ECHO} "CFLAGS += -DMD5_PW" >> ${WRKDIR}/All/${OSNAME}/Makefile.include
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/w3c-httpd ${PREFIX}/share/w3c-httpd
	${CP} -R ${WRKSRC}/server_root/icons ${PREFIX}/share/w3c-httpd
	${CP} ${WRKSRC}/server_root/config/*.conf ${EGDIR:Q}
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/httpd ${PREFIX}/sbin/w3c-httpd
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/htadm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/htimage ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/cgiparse ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/cgiutils ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"

.if (${OPSYS} == "FreeBSD") || (${OPSYS} == "DragonFly")
OSNAME=	freebsd
.else
#	covers OpenBSD too
OSNAME=	netbsd
.endif
