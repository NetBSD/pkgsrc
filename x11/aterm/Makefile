# $NetBSD: Makefile,v 1.43 2012/09/29 17:59:34 asau Exp $
#

DISTNAME=	aterm-1.0.0
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aterm/}
EXTRACT_SUFX=	.tar.bz2
#CVS_ROOT=	:pserver:anonymous@cvs.aftercode.net:/home/cvsroot
#CVS_MODULE=	aterm1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.afterstep.org/aterm.php
COMMENT=	Aterm (Afterstep XVT) - a VT102 emulator for the X window system

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
MAKE_JOBS_SAFE=	no

CONFIGURE_ARGS+=--enable-background-image \
		--enable-transparency \
		--enable-fading \
		--enable-graphics \
		--with-xpm \
		--with-xpm-includes=${BUILDLINK_PREFIX.libXpm}/include \
		--with-xpm-library=${BUILDLINK_PREFIX.libXpm}/lib \
		--with-jpeg \
		--with-jpeg-includes=${JPEGBASE}/include \
		--with-jpeg-library=${JPEGBASE}/lib \
		--with-png \
		--with-png-library=${BUILDLINK_PREFIX.png}/lib \
		--with-png-includes=${BUILDLINK_PREFIX.png}/include \
		--enable-utmp \
		--enable-wtmp

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "Darwin"
# Make aterm setuid root so that tty ownership setting and utmp logging
# function correctly.
#
CONFIGURE_ARGS+=	--enable-ttygid
SPECIAL_PERMS=		${PREFIX}/bin/aterm ${SETUID_ROOT_PERMS}
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
