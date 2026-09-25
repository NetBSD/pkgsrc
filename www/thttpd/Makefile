# $NetBSD: Makefile,v 1.55 2026/09/25 14:20:39 wiz Exp $

DISTNAME=		thttpd-2.29
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		https://www.acme.com/software/thttpd/
DIST_SUBDIR=		${PKGNAME_NOREV}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${NETBSD_LOGO}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
NETBSD_LOGO=		sitedrivenby.gif
SITES.${NETBSD_LOGO}=	http://www.NetBSD.org/images/logos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.acme.com/software/thttpd/
COMMENT=	Tiny/turbo/throttling HTTP server
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

# cgi-src/Makefile.in builds strerror.o by running make in the parent
# directory ("cd .. ; $(MAKE) strerror.o"), and the top Makefile runs
# "all: this subdirs", so with -j the parent's own build and the
# subdirectory's can compile that object into the same file at once.
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	IPV6_READY

# thttpd syslogs at level LOG_DAEMON by default; change this to your
# preferred syslog level.
THTTPD_LOG_FACILITY?=	LOG_DAEMON
BUILD_DEFS+=		THTTPD_LOG_FACILITY

# glibc declares sigset(3) only under _XOPEN_SOURCE.  configure finds the
# symbol anyway (it links), so HAVE_SIGSET is defined and thttpd.c calls it
# with no prototype in scope.
CFLAGS.Linux+=	-D_GNU_SOURCE

# illumos declares crypt(3c) in <unistd.h> only under __EXTENSIONS__, and
# thttpd includes no <crypt.h>.
CFLAGS.SunOS+=	-D__EXTENSIONS__

CFLAGS.SCO_SV+=	-DMAXPATHLEN=255 -DS_IFSOCK=0

EGDIR=		${PREFIX}/share/examples
DOCDIR=		${PREFIX}/share/doc/thttpd

CONF_FILES=	${EGDIR}/thttpd.conf ${PKG_SYSCONFDIR}/thttpd.conf
RCD_SCRIPTS=	thttpd

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/thttpd ${EGDIR} ${DOCDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	thttpd.conf README.pkgsrc
SUBST_VARS.paths=	PREFIX

# htpasswd(1) is a common name, so the package installs it as thtpasswd.
# post-patch does the renaming: after the patches, which still name
# extras/htpasswd.c, and before this substitution runs.
SUBST_CLASSES+=			thtpasswd
SUBST_STAGE.thtpasswd=		pre-configure
SUBST_MESSAGE.thtpasswd=	Renaming htpasswd to thtpasswd.
SUBST_FILES.thtpasswd=		thttpd.8 extras/Makefile.in extras/thtpasswd.c
SUBST_SED.thtpasswd=		-e 's,\.htpasswd,@DOTHTPASSWD@,g'
SUBST_SED.thtpasswd+=		-e 's,htpasswd,thtpasswd,g'
SUBST_SED.thtpasswd+=		-e 's,@DOTHTPASSWD@,.htpasswd,g'

SUBST_CLASSES+=		logfac
SUBST_STAGE.logfac=	pre-configure
SUBST_MESSAGE.logfac=	Setting the syslog facility.
SUBST_FILES.logfac=	config.h
SUBST_SED.logfac=	-e 's,LOG_DAEMON,${THTTPD_LOG_FACILITY},'

post-extract:
	${CP} ${FILESDIR}/thttpd.conf ${WRKSRC}
	${CP} ${FILESDIR}/README.pkgsrc ${WRKSRC}

post-patch:
	${MV} ${WRKSRC}/extras/htpasswd.1 ${WRKSRC}/extras/thtpasswd.1
	${MV} ${WRKSRC}/extras/htpasswd.c ${WRKSRC}/extras/thtpasswd.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.pkgsrc ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/thttpd.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html \
		${DESTDIR}${PREFIX}/share/thttpd
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${NETBSD_LOGO} \
		${DESTDIR}${PREFIX}/share/thttpd

.include "../../mk/bsd.pkg.mk"
