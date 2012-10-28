# $NetBSD: Makefile,v 1.44 2012/10/28 06:31:06 asau Exp $

DISTNAME=	thttpd-2.25b
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thttpd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${NETBSD_LOGO}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/thttpd/
COMMENT=	Tiny/turbo/throttling HTTP server

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

NETBSD_LOGO=		sitedrivenby.gif
SITES.${NETBSD_LOGO}=	http://www.NetBSD.org/images/logos/

GNU_CONFIGURE=	yes

# Note: this pkg auto-detects IPv6.
BUILD_DEFS+=	IPV6_READY
# thttpd syslogs at level LOG_DAEMON by default
# change this to your preferred syslog level
THTTPD_LOG_FACILITY?=	LOG_DAEMON
BUILD_DEFS+=	THTTPD_LOG_FACILITY

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/thttpd.conf ${PKG_SYSCONFDIR}/thttpd.conf
RCD_SCRIPTS=	thttpd

INSTALLATION_DIRS=	$(PKGMANDIR)/man1 share/thttpd

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	thttpd.conf
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

MAKE_JOBS_SAFE=	no

post-extract:
	${CP} ${FILESDIR}/thttpd.conf ${WRKSRC}

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

post-install:
	${INSTALL_DATA} ${WRKSRC}/thttpd.conf ${DESTDIR}${PREFIX}/share/examples
	${INSTALL_DATA} ${WRKSRC}/index.html ${DESTDIR}${PREFIX}/share/thttpd
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/sitedrivenby.gif ${DESTDIR}${PREFIX}/share/thttpd

.include "../../mk/bsd.pkg.mk"
