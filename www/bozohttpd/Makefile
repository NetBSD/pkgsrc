# $NetBSD: Makefile,v 1.101 2024/03/16 20:38:43 nia Exp $
#

DISTNAME=	bozohttpd-20240126
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	Bozotic HTTP server; small and secure
LICENSE=	2-clause-bsd

BOZO_CFLAGS+=		-DNO_BLOCKLIST_SUPPORT
BOZO_CFLAGS+=		-D_GNU_SOURCE -D_DEFAULT_SOURCE

.include "options.mk"

MAKE_FILE=		Makefile.boot

# Honor pkgsrc's optimization settings, necessary when
# combined with FORTIFY_SOURCE on e.g. Linux.
MAKE_FLAGS+=		OPT=${CFLAGS:Q}

# Apply our settings.
MAKE_FLAGS+=		LOCAL_CFLAGS=${BOZO_CFLAGS:Q}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths in manual page.
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	bozohttpd.8
SUBST_SED.paths=	-e "s|/usr/pkg/|"${PREFIX:Q}"/|g"

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man8

# Macs lacked clock_gettime way past its implement-by date.
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 101200
LDFLAGS+=	-lMacportsLegacySupport
.  include "../../devel/macports-legacy-support/buildlink3.mk"
.endif

LDFLAGS.SunOS+=		-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bozohttpd ${DESTDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/bozohttpd.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
