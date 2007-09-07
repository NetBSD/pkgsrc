# $NetBSD: Makefile,v 1.58 2007/09/07 22:12:24 jlam Exp $
#

DISTNAME=	bozohttpd-20060517
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	http://www.eterna.com.au/bozohttpd/
COMMENT=	Bozotic HTTP server; small and secure

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}
MAKE_ENV+=	MANOWN=${MANOWN} MANGRP=${MANGRP} MANMODE=${MANMODE}

PKG_OPTIONS_VAR=	PKG_OPTIONS.bozohttpd
PKG_SUPPORTED_OPTIONS=	bozohttpd-do-htpasswd inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbozohttpd-do-htpasswd)
CPPFLAGS+=	-DDO_HTPASSWD
.endif

.if !empty(PKG_OPTIONS:Minet6)
CPPFLAGS+=	-DINET6
.endif

CPPFLAGS+=	-Wno-error
MAKE_ENV+=	BINDIR=${PREFIX}/libexec MANDIR=${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

.include "../../security/openssl/buildlink3.mk"

pre-build:
	cd ${WRKSRC}; for file in bozohttpd.8; do			\
		${SED}	-e "s|/usr/pkg/|${PREFIX}/|g"			\
			$${file} >> $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../mk/bsd.pkg.mk"
