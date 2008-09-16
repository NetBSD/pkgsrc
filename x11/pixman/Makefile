# $NetBSD: Makefile,v 1.20 2008/09/16 21:22:34 bjs Exp $
#

DISTNAME=	pixman-0.11.10
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
USE_TOOLS+=	pkg-config perl diff
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
###	To regenerate the libtool symfile, invoke the 'gen-symfile'
###	target, making sure to define PKG_DEVELOPER.  This target
###	requires nm, awk, and tee.  The new symfile will be in
###	${WRKDIR}.
###
MAKE_ENV+=	PIXMAN_SYMFILE=${PIXMAN_SYMFILE:Q}
PIXMAN_SYMFILE=	${WRKDIR}/pixman.sym

post-extract:
	${CP} ${FILESDIR}/pixman.sym ${WRKDIR}

.if defined(NM) && defined(PKG_DEVELOPER)
.PHONY: gen-symfile
gen-symfile: build
	${NM} -DP ${WRKSRC}/pixman/.libs/libpixman-1.so | 	\
	${AWK} '/^pixman/ { print $$1 }' | 			\
	${TOOLS_PLATFORM.tee} > ${WRKDIR}/pixman.sym &&		\
	${DIFF} ${FILESDIR}/pixman.sym ${WRKDIR}/pixman.sym
.endif

.include "../../mk/bsd.pkg.mk"
