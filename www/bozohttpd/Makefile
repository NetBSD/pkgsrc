# $NetBSD: Makefile,v 1.55 2006/06/10 20:00:55 minskim Exp $
#

DISTNAME=	bozohttpd-20060517
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	Bozotic HTTP server; small and secure

BUILD_DEFS+=	USE_INET6

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}
MAKE_ENV+=	MANOWN=${MANOWN} MANGRP=${MANGRP} MANMODE=${MANMODE}

PKG_OPTIONS_VAR=	PKG_OPTIONS.bozohttpd
PKG_SUPPORTED_OPTIONS=	bozohttpd-do-htpasswd

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CPPFLAGS+=	-DINET6
.endif
CPPFLAGS+=	-Wno-error
MAKE_ENV+=	BINDIR=${PREFIX}/libexec MANDIR=${PREFIX}/man

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbozohttpd-do-htpasswd)
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
