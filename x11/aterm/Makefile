# $NetBSD: Makefile,v 1.32 2006/12/15 20:33:03 joerg Exp $
#

DISTNAME=	aterm-1.0.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aterm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.afterstep.org/aterm.php
COMMENT=	Aterm (Afterstep XVT) - a VT102 emulator for the X window system

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--enable-background-image \
		--enable-transparency \
		--enable-fading \
		--enable-graphics \
		--with-xpm \
		--with-xpm-includes=${BUILDLINK_PREFIX.xpm}/include \
		--with-xpm-library=${BUILDLINK_PREFIX.xpm}/lib \
		--with-jpeg \
		--with-jpeg-includes=${BUILDLINK_PREFIX.jpeg}/include \
		--with-jpeg-library=${BUILDLINK_PREFIX.jpeg}/lib \
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

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
