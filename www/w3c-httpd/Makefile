# $NetBSD: Makefile,v 1.4 1999/09/28 20:40:05 soren Exp $
# FreeBSD Id: Makefile,v 1.19 1999/01/08 19:59:26 fenner Exp

DISTNAME=	w3c-httpd-3.0A
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/httpd/ \
		ftp://ftp-eu.w3.org/pub/httpd/

MAINTAINER=	package@netbsd.org
HOMEPAGE=	http://www.w3.org/pub/WWW/Daemon/

NO_WRKSUBDIR=	yes

pre-configure:
.if !defined(MD5_PW)
	@echo ""
	@echo "Defaulting to DES encrypted passwords."
	@echo "Set the environment variable MD5_PW if you want MD5 encrypted passwords."
	@echo ""
.else
	@echo "CFLAGS += -DMD5_PW" >> ${WRKDIR}/All/${OSNAME}/Makefile.include
.endif

do-install:
	${MKDIR} ${PREFIX}/etc/w3c-httpd ${PREFIX}/share/w3c-httpd
	${CP} -R ${WRKSRC}/server_root/icons ${PREFIX}/share/w3c-httpd
	${CP} ${WRKSRC}/server_root/config/*.conf ${PREFIX}/etc/w3c-httpd
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/httpd ${PREFIX}/sbin/w3c-httpd
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/htadm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/htimage ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/cgiparse ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/${OSNAME}/cgiutils ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"

.if (${OPSYS} == "FreeBSD")
OSNAME=	freebsd
.else
#	covers OpenBSD too
OSNAME=	netbsd
.endif
