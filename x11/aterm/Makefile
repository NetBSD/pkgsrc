# $NetBSD: Makefile,v 1.25 2005/12/29 06:22:25 jlam Exp $
#

DISTNAME=	aterm-0.4.2
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aterm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://aterm.sourceforge.net/
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
CONFIGURE_ARGS+=--enable-ttygid
SPECIAL_PERMS=	${PREFIX}/bin/aterm ${SETUID_ROOT_PERMS}
.endif

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
