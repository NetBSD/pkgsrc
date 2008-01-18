# $NetBSD: Makefile,v 1.60 2008/01/18 05:09:48 tnn Exp $
#

DISTNAME=	bozohttpd-20060517
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	Bozotic HTTP server; small and secure

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_FILE=		Makefile.boot

PKG_OPTIONS_VAR=	PKG_OPTIONS.bozohttpd
PKG_SUPPORTED_OPTIONS=	bozohttpd-do-htpasswd inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbozohttpd-do-htpasswd)
CPPFLAGS+=	-DDO_HTPASSWD
.endif

.if !empty(PKG_OPTIONS:Minet6)
CPPFLAGS+=	-DINET6
.endif

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths in manual page.
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	bozohttpd.8
SUBST_SED.paths=	-e "s|/usr/pkg/|"${PREFIX:Q}"/|g"

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bozohttpd ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/bozohttpd.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
