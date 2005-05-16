# $NetBSD: Makefile,v 1.55 2005/05/16 01:15:34 jlam Exp $

DISTNAME=	wwwoffle-2.8e
CATEGORIES=	www
MASTER_SITES=	http://www.gedanken.freeserve.co.uk/download-wwwoffle/ \
		ftp://ftp.ibiblio.org/pub/Linux/apps/www/servers/
EXTRACT_SUFX=	.tgz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/wwwoffle/
COMMENT=	WWW proxy with support for offline browsing

USE_TOOLS+=	gtar
USE_GNU_TOOLS+=	make
USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+= --with-confdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+= --with-spooldir=${VARBASE}/wwwoffle

PKG_SYSCONFSUBDIR= 	wwwoffle
PLIST_SUBST+=		GTAR="${GTAR}"
INSTALL_EXTRA_TMPL=	${PKGDIR}/INSTALL

RCD_SCRIPTS=		wwwoffled

BUILD_DEFS+=		USE_INET6

post-build:
	cd ${WRKSRC}/cache/search/htdig/scripts; \
	for f in wwwoffle-ht*; do \
		${MV} $$f $$f.old; \
		${SED} -e '/htsearch/s#^#${PREFIX}/libexec/cgi-bin/#' \
		  -e 's#/usr/local#${PREFIX}#' $$f.old > $$f; \
		${RM} $$f.old; \
	done

# For bulk-build machines: a one-time install/deinstall, if wwwoffle
# is never run, leaves an incomplete cache directory, which the install
# target incorrectly calculates to be a pre-2.2 cache. This tricks it
# into setting up the cache directory properly.
pre-install:
	${MKDIR} ${VARBASE}/wwwoffle/prevtime1

post-install:
	if [ -f ${PKG_SYSCONFDIR}/wwwoffle.conf.install ]; then \
		${CP} -p ${PKG_SYSCONFDIR}/wwwoffle.conf.install \
		  ${PREFIX}/share/examples/wwwoffle.conf; \
	elif [ -f ${PKG_SYSCONFDIR}/wwwoffle.conf ]; then \
		${CP} -p ${PKG_SYSCONFDIR}/wwwoffle.conf \
		  ${PREFIX}/share/examples/wwwoffle.conf; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/src/convert-cache \
	  ${PREFIX}/sbin/wwwoffle-convert-cache
	${INSTALL_PROGRAM} ${WRKSRC}/src/uncompress-cache \
	  ${PREFIX}/sbin/wwwoffle-uncompress-cache
	${INSTALL_SCRIPT} ${WRKSRC}/conf/upgrade-config.pl \
	  ${PREFIX}/sbin/wwwoffle-upgrade-config.pl
	${INSTALL_SCRIPT} ${WRKSRC}/conf/upgrade-config-2.x-2.5.pl \
	  ${PREFIX}/sbin/wwwoffle-upgrade-config-2.x-2.5.pl
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
	${SETENV} CONFDIR="${PKG_SYSCONFDIR}" PKG_PREFIX="${PREFIX}" \
		${SH} INSTALL _ POST-INSTALL

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CONFIGURE_ARGS+= --with-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
