# $NetBSD: Makefile,v 1.37 2002/07/16 14:28:07 fredb Exp $

DISTNAME=	wwwoffle-2.7c
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/unix/httpd/ \
		http://www.gedanken.freeserve.co.uk/download-wwwoffle/ \
		${MASTER_SITE_SUNSITE:=apps/www/servers/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/wwwoffle/
COMMENT=	WWW proxy with support for offline browsing

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+= --with-confdir=${PKG_SYSCONFDIR}/wwwoffle
CONFIGURE_ARGS+= --with-spooldir=/var/wwwoffle

PLIST_SUBST+=	GTAR="${GTAR}" PKG_SYSCONFDIR="${PKG_SYSCONFDIR}"

post-build:
	cd ${WRKSRC}/cache/search/htdig/scripts; \
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

post-install:
	if [ ! -f ${PREFIX}/etc/wwwoffle/wwwoffle.conf.install ]; then \
		${CP} -p ${PREFIX}/etc/wwwoffle/wwwoffle.conf \
		  ${PREFIX}/etc/wwwoffle/wwwoffle.conf.install; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/src/convert-cache \
	  ${PREFIX}/sbin/wwwoffle-convert-cache
	${INSTALL_PROGRAM} ${WRKSRC}/src/uncompress-cache \
	  ${PREFIX}/sbin/wwwoffle-uncompress-cache
	${INSTALL_SCRIPT} ${WRKSRC}/conf/upgrade-config.pl \
	  ${PREFIX}/sbin/wwwoffle-upgrade-config.pl
	${INSTALL_SCRIPT} ${WRKSRC}/conf/upgrade-config-2.x-2.5.pl \
	  ${PREFIX}/sbin/wwwoffle-upgrade-config-2.x-2.5.pl
	${INSTALL_SCRIPT} ${WRKDIR}/wwwoffle.sh ${PREFIX}/etc/rc.d/wwwoffle
	${INSTALL_SCRIPT} ${WRKDIR}/wwwoffled ${PREFIX}/etc/rc.d
# Directories other than html and search are automatically created at run time
	${GTAR} czCf / ${PREFIX}/libdata/wwwoffle-spool.tar.gz \
		var/wwwoffle/html var/wwwoffle/search
	@${ECHO}
	@${ECHO} ==+===+===+===+===+===+===+===+===+===+===+===+===+===+===+=
	@${ECHO}
	@${ECHO} Attention pkgsrc source users:
	@${ECHO}
	@${ECHO} 'Please run' "\`make finish'" 'from this directory *after*'
	@${ECHO} '(optionally) running' "\`make package'", 'in order to fix'
	@${ECHO} 'up the installed "wwwoffle.pac" files to your hostname'
	@${ECHO} 'and convert your config file and cache to the new format.'
	@${ECHO}
	@${ECHO} ==+===+===+===+===+===+===+===+===+===+===+===+===+===+===+=
	@${ECHO}

# We don't do the following automatically, as that would inconvenience
# package build machines, not to mention putting the wrong information
# into the "wwwoffle.pac" files.
finish:
	${SH} INSTALL _ POST-INSTALL

.include "../../mk/bsd.prefs.mk"

.if ${USE_INET6} == "YES"
CONFIGURE_ARGS+= --with-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
