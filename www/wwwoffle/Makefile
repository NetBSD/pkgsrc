# $NetBSD: Makefile,v 1.9 1999/09/03 21:57:49 tron Exp $

DISTNAME=	wwwoffle-2.4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/unix/httpd/ \
		${MASTER_SITE_SUNSITE:=apps/www/servers/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/wwwoffle/

USE_GMAKE=	yes
NO_CONFIGURE=	yes

MESSAGE_FILE=	${WRKDIR}/MESSAGE
PLIST_SRC=	${WRKDIR}/PLIST

BUILD_DEFS+=	USE_INET6

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"

# IPv6 support
.if defined(USE_INET6) && ${USE_INET6} == YES
PATCHDIR=       ${WRKDIR}/.patches
.endif

pre-patch:
.if defined(USE_INET6) && ${USE_INET6} == YES
	${MKDIR} ${WRKDIR}/.patches
	${CP} ${.CURDIR}/patches/patch-* ${WRKDIR}/.patches
	${CP} ${.CURDIR}/patches.v6/patch-* ${WRKDIR}/.patches
.endif

post-build:
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${FILESDIR}/wwwoffle.sh \
	  >${WRKDIR}/wwwoffle.sh
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/MESSAGE \
	  >${MESSAGE_FILE}
	@${SED} -e 's#@GTAR@#${GTAR}#g' <${PKGDIR}/PLIST >${PLIST_SRC}

pre-install:
	${MKDIR} ${PREFIX}/etc/wwwoffle

post-install:
	if [ -f ${PREFIX}/etc/wwwoffle/wwwoffle.conf.install ]; then \
	  ${MV} ${PREFIX}/etc/wwwoffle/wwwoffle.conf.install \
		${PREFIX}/etc/wwwoffle/wwwoffle.conf.default; \
	else \
	  ${CP} -p ${PREFIX}/etc/wwwoffle/wwwoffle.conf \
	    ${PREFIX}/etc/wwwoffle/wwwoffle.conf.default; \
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/wwwoffle.sh ${PREFIX}/etc/rc.d
	${CHOWN} -R ${BINOWN}:${BINGRP} /var/wwwoffle
	${GTAR} czCf / ${PREFIX}/libdata/wwwoffle-spool.tar.gz var/wwwoffle

.include "../../mk/bsd.pkg.mk"
