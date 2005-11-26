# $NetBSD: Makefile,v 1.32.2.1 2005/11/26 10:42:15 salo Exp $

DISTNAME=	thttpd-2.25b
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thttpd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${NETBSD_LOGO}
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.acme.com/software/thttpd/
COMMENT=	Tiny/turbo/throttling HTTP server

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

NETBSD_LOGO=		sitedrivenby.gif
SITES_${NETBSD_LOGO}=	http://www.NetBSD.org/images/logos/

GNU_CONFIGURE=	yes
USE_PKGINSTALL=	yes

# Note: this pkg auto-detects IPv6 without regarding USE_INET6.
BUILD_DEFS+=	USE_INET6
# thttpd syslogs at level LOG_DAEMON by default
# change this to your preferred syslog level
THTTPD_LOG_FACILITY?=	LOG_DAEMON
BUILD_DEFS+=	THTTPD_LOG_FACILITY

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/thttpd.conf ${PKG_SYSCONFDIR}/thttpd.conf
RCD_SCRIPTS=	thttpd

INSTALLATION_DIRS=	share/thttpd

pre-configure:
	${MV} ${WRKSRC}/extras/htpasswd.1 ${WRKSRC}/extras/thtpasswd.1
	${MV} ${WRKSRC}/extras/htpasswd.c ${WRKSRC}/extras/thtpasswd.c
	for FILE in thttpd.8 extras/Makefile.in extras/thtpasswd.c; do	\
		${MV} -f ${WRKSRC}/$${FILE} ${WRKSRC}/$${FILE}.bak;	\
		${SED}	-e "s,\.htpasswd,XXX,g;s,htpasswd,thtpasswd,g;s,XXX,.htpasswd,g" \
			${WRKSRC}/$${FILE}.bak > ${WRKSRC}/$${FILE};	\
	done
	${MV} -f ${WRKSRC}/config.h ${WRKSRC}/config.h.bak
	${SED} -e "s/LOG_DAEMON/${THTTPD_LOG_FACILITY}/" ${WRKSRC}/config.h.bak \
			> ${WRKSRC}/config.h

post-build:
	@for FILE in thttpd.conf; do					\
		${SED}	${FILES_SUBST_SED}				\
			${FILESDIR}/$${FILE} > ${WRKDIR}/$${FILE};	\
	done

post-install:
	${INSTALL_DATA} ${WRKDIR}/thttpd.conf ${PREFIX}/share/examples
	${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/share/thttpd
	${INSTALL_DATA} ${DISTDIR}/sitedrivenby.gif ${PREFIX}/share/thttpd

.include "../../mk/bsd.pkg.mk"
