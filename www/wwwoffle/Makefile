# $NetBSD: Makefile,v 1.34 2002/03/25 08:49:59 fredb Exp $

DISTNAME=	wwwoffle-2.7a
PKGNAME=	wwwoffle-2.7.1
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
# We don't do the following automatically, as that would inconvenience
# package build machines, not to mention putting the wrong information
# in the "wwwoffle.pac" files.
	@${ECHO}
	@${ECHO} ==+===+===+===+===+===+===+===+===+===+===+===+===+===+===+=
	@${ECHO}
	@${ECHO} Attention pkgsrc source users:
	@${ECHO}
	@${ECHO} "Running \`sh INSTALL _ POST-INSTALL' from this directory"
	@${ECHO} 'will fix up the installed "wwwoffle.pac" files and convert'
	@${ECHO} 'your old cache to the new format, exactly as in the binary'
	@${ECHO} 'package install.'
	@${ECHO}
	@${ECHO} ==+===+===+===+===+===+===+===+===+===+===+===+===+===+===+=
	@${ECHO}

.include "../../mk/bsd.prefs.mk"

.if ${USE_INET6} == "YES"
CONFIGURE_ARGS+= --with-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
