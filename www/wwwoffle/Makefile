# $NetBSD: Makefile,v 1.31 2001/08/14 04:51:46 fredb Exp $

DISTNAME=	wwwoffle-2.6d
CATEGORIES=	www
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-wwwoffle/ \
		ftp://ftp.demon.co.uk/pub/unix/httpd/ \
		${MASTER_SITE_SUNSITE:=apps/www/servers/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/wwwoffle/
COMMENT=	WWW proxy with support for offline browsing

USE_GMAKE=	yes
NO_CONFIGURE=	yes

PLIST_SUBST+=	GTAR="${GTAR}" MKDIR="${MKDIR}" PREFIX="${PREFIX}"

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

.if ${USE_INET6} == "YES"
MAKE_ENV+=	USE_IPV6=1
.else
MAKE_ENV+=	USE_IPV6=0
.endif

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	LIBRARY="-lnsl -lsocket"
.endif

post-build:
	cd ${WRKSRC}/html/search/htdig/scripts; \
	for f in wwwoffle-ht*; do \
		${MV} $$f $$f.old; \
		${SED} -e '/htsearch/s#^#${PREFIX}/libexec/cgi-bin/#' \
		  -e 's#/usr/local#${PREFIX}#' <$$f.old >$$f; \
		${RM} $$f.old; \
	done
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${FILESDIR}/wwwoffle.sh \
	  >${WRKDIR}/wwwoffle.sh
	@${SED} -e 's#@PREFIX@#${PREFIX}#g' <${FILESDIR}/wwwoffled \
	  >${WRKDIR}/wwwoffled

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/wwwoffle
	if [ -d /var/wwwoffle ]; then \
	  ${RM} -rf /var/wwwoffle/html.old; \
	  ${INSTALL_DATA_DIR} /var/wwwoffle/prevtime1; \
	fi

post-install:
	if [ -f ${PREFIX}/etc/wwwoffle/wwwoffle.conf.install ]; then \
	  ${MV} ${PREFIX}/etc/wwwoffle/wwwoffle.conf.install \
		${PREFIX}/etc/wwwoffle/wwwoffle.conf.default; \
	else \
	  ${CP} -p ${PREFIX}/etc/wwwoffle/wwwoffle.conf \
	    ${PREFIX}/etc/wwwoffle/wwwoffle.conf.default; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/convert-cache \
	  ${PREFIX}/sbin/wwwoffle-convert-cache
	${INSTALL_SCRIPT} ${WRKSRC}/upgrade-config.pl \
	  ${PREFIX}/sbin/wwwoffle-upgrade-config.pl
	${INSTALL_SCRIPT} ${WRKSRC}/upgrade-config-2.x-2.5.pl \
	  ${PREFIX}/sbin/wwwoffle-upgrade-config-2.x-2.5.pl
	${INSTALL_SCRIPT} ${WRKDIR}/wwwoffle.sh ${PREFIX}/etc/rc.d/wwwoffle
	${INSTALL_SCRIPT} ${WRKDIR}/wwwoffled ${PREFIX}/etc/rc.d
	# directories other than html are automatically created at run time
	${GTAR} czCf / ${PREFIX}/libdata/wwwoffle-spool.tar.gz var/wwwoffle/html
	@${ECHO}
	@${ECHO} ==+===+===+===+===+===+===+===+===+===+===+===+===+===+===+=
	@${ECHO}
	@${ECHO} Attention pkgsrc source users:
	@${ECHO}
	@${ECHO} If your are upgrading from an older version of wwwoffle,
	@${ECHO} your cache will not be converted automatically. Please do
	@${ECHO} so by executing the command
	@${ECHO} \"${PREFIX}/libexec/wwwoffle-convert-cache /var/wwwoffle\".
	@${ECHO}
	@${ECHO} ==+===+===+===+===+===+===+===+===+===+===+===+===+===+===+=
	@${ECHO}

.include "../../mk/bsd.pkg.mk"
