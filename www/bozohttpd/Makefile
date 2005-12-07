# $NetBSD: Makefile,v 1.50 2005/12/07 17:01:22 bad Exp $
#

DISTNAME=	bozohttpd-20050410
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	Bozotic HTTP server; small and secure

BUILD_DEFS+=	USE_INET6

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKG_OPTIONS_VAR=	PKG_OPTIONS.bozohttpd
PKG_SUPPORTED_OPTIONS=	do_htpasswd

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CPPFLAGS+=	-DINET6
.endif
CPPFLAGS+=	-Wno-error
MAKE_ENV+=	BINDIR=${PREFIX}/libexec MANDIR=${PREFIX}/man

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdo_htpasswd)
CPPFLAGS+=	-DDO_HTPASSWD
.endif

INSTALLATION_DIRS=	libexec man/cat8 man/man8

.include "../../security/openssl/buildlink3.mk"

pre-build:
	cd ${WRKSRC}; for file in bozohttpd.8; do			\
		${SED}	-e "s|/usr/pkg/|${PREFIX}/|g"			\
			$${file} >> $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../mk/bsd.pkg.mk"
