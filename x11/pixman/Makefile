# $NetBSD: Makefile,v 1.13 2008/06/19 17:59:52 bjs Exp $
#

DISTNAME=	pixman-0.11.4
PKGNAME=	${DISTNAME:C/pl[0-9]*//}
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

PKGCONFIG_OVERRIDE+=	pixman-1.pc.in
###
### XXX The configure script is written to fail if it detects gcc<4.0
###	for lack of -fvisibility=hidden. In keeping with the pkgsrc
###	tradition of portability, we'll opt to use libtool to export
###	the desired symbols, hiding the rest.
###
###	I have verified the list of visible symbols is unchanged from
###	the "factory" build.
###
PIXMAN_SYMFILE=	${WRKDIR}/pixman.sym
MAKE_ENV+=		PIXMAN_SYMFILE=${PIXMAN_SYMFILE:Q}

post-extract:
	${CP} ${FILESDIR}/pixman.sym ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
