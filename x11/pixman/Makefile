# $NetBSD: Makefile,v 1.26 2009/06/08 09:04:32 wiz Exp $
#

DISTNAME=	pixman-0.15.10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Library of low-level pixel manipulation routines

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl
###
### XXX Quiet, please!
###
.if empty(USE_TOOLS:Mauto*)
CONFIGURE_ENV+=	AUTOCONF=${TRUE:Q}
CONFIGURE_ENV+=	AUTOHEADER=${TRUE:Q}
CONFIGURE_ENV+=	ACLOCAL=${TRUE:Q}
CONFIGURE_ENV+=	AUTOMAKE=${TRUE:Q}
.endif

PKGCONFIG_OVERRIDE+=	pixman-1.pc.in
PKGCONFIG_OVERRIDE+=	pixman-1-uninstalled.pc.in
###
### XXX The configure script is written to fail if it detects gcc<4.0
###	for lack of -fvisibility=hidden. In keeping with the pkgsrc
###	tradition of portability, we'll opt to use libtool to export
###	the desired symbols, hiding the rest.
###
###	Please, do not forget to ensure the currency of this file!

MAKE_ENV+=	PIXMAN_SYMFILE=${PIXMAN_SYMFILE:Q}
PIXMAN_SYMFILE=	${WRKDIR}/pixman.sym

post-extract:
	${CP} ${FILESDIR}/pixman.sym ${WRKDIR}
	${CP} ${FILESDIR}/solaris-hwcap.mapfile ${WRKSRC}/pixman

.include "../../mk/bsd.pkg.mk"
