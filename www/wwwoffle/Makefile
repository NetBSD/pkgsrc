# $NetBSD: Makefile,v 1.20 2000/11/20 05:12:38 itojun Exp $

DISTNAME=	wwwoffle-2.6
CATEGORIES=	www
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-wwwoffle/ \
		ftp://ftp.demon.co.uk/pub/unix/httpd/ \
		${MASTER_SITE_SUNSITE:=apps/www/servers/}
EXTRACT_SUFX=	.tgz

PATCHFILES+=	wwwoffle-26-v6-20001120.diff.gz
PATCH_SITES+=	ftp://ftp.kame.net/pub/kame/misc/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/wwwoffle/

USE_GMAKE=	yes
NO_CONFIGURE=	yes

MESSAGE_FILE=	${WRKDIR}/MESSAGE
PLIST_SRC=	${WRKDIR}/PLIST

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	LIBRARY="-lnsl -lsocket"
.endif

post-build:
	cd ${WRKSRC}/html/htdig/scripts; \
	for f in wwwoffle-ht*; do \
		${MV} $$f $$f.old; \
		${SED} -e '/htsearch/s#^#${PREFIX}/libexec/cgi-bin/#' \
		  -e 's#/usr/local#${PREFIX}#' <$$f.old >$$f; \
		${RM} $$f.old; \
	done
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${FILESDIR}/wwwoffle.sh \
	  >${WRKDIR}/wwwoffle.sh
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${PKGDIR}/MESSAGE \
	  >${MESSAGE_FILE}
	@${SED} -e 's#@GTAR@#${GTAR}#g' <${PKGDIR}/PLIST >${PLIST_SRC}

pre-install:
	${MKDIR} ${PREFIX}/etc/wwwoffle
	if [ -d /var/wwwoffle ]; then \
	  ${RM} -rf /var/wwwoffle/html.old; \
	  ${MKDIR} /var/wwwoffle/http; \
	fi

post-install:
	if [ -f ${PREFIX}/etc/wwwoffle/wwwoffle.conf.install ]; then \
	  ${MV} ${PREFIX}/etc/wwwoffle/wwwoffle.conf.install \
		${PREFIX}/etc/wwwoffle/wwwoffle.conf.default; \
	else \
	  ${CP} -p ${PREFIX}/etc/wwwoffle/wwwoffle.conf \
	    ${PREFIX}/etc/wwwoffle/wwwoffle.conf.default; \
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/wwwoffle.sh ${PREFIX}/etc/rc.d
	${CHOWN} -R -h ${BINOWN}:${BINGRP} /var/wwwoffle
	# directories other than html are automatically created at run time
	${GTAR} czCf / ${PREFIX}/libdata/wwwoffle-spool.tar.gz	\
	  var/wwwoffle/html var/wwwoffle/outgoing

.include "../../mk/bsd.pkg.mk"
