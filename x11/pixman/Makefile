# $NetBSD: Makefile,v 1.17 2008/07/18 19:03:32 bjs Exp $
#

DISTNAME=	pixman-0.11.8
PKGREVISION=	1
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

CONFIGURE_ENV+=	AUTOMAKE=${TRUE:Q}	# XXX quiet!

PKGCONFIG_OVERRIDE+=	pixman-1.pc.in
PKGCONFIG_OVERRIDE+=	pixman-1-uninstalled.pc.in
###
### XXX The configure script is written to fail if it detects gcc<4.0
###	for lack of -fvisibility=hidden. In keeping with the pkgsrc
###	tradition of portability, we'll opt to use libtool to export
###	the desired symbols, hiding the rest.
###
###	I have verified the list of visible symbols is unchanged from
###	the "factory" build.
###
MAKE_ENV+=	PIXMAN_SYMFILE=${PIXMAN_SYMFILE:Q}
PIXMAN_SYMFILE=	${WRKDIR}/pixman.sym

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro) || empty(CC_VERSION:Mgcc-4.1*)
CONFIGURE_ARGS+=	--disable-sse2
.endif

post-extract:
	${CP} ${FILESDIR}/pixman.sym ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
