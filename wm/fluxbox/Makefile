# $NetBSD: Makefile,v 1.18 2004/10/03 00:18:22 tv Exp $
#

DISTNAME=	fluxbox-0.9.10
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxbox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://fluxbox.sourceforge.net/
COMMENT=	Window Manager for X based on Blackbox

DEPENDS=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_BUILDLINK3=	YES
USE_X11=	YES
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-xinerama

.include "../../mk/bsd.prefs.mk"

FLUXBOX_USE_KDE?=	NO
.if !empty(FLUXBOX_USE_KDE:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-kde
.endif

FLUXBOX_USE_GNOME?=	NO
.if !empty(FLUXBOX_USE_GNOME:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-gnome
.elseif
CONFIGURE_ARGS+=	--disable-gnome
.endif

FLUXBOX_USE_XFT?=	YES
.if !empty(FLUXBOX_USE_XFT:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-xft
.include "../../fonts/Xft2/buildlink3.mk"
.elseif
CONFIGURE_ARGS+=	--disable-xft
.endif

.include "../../mk/bsd.pkg.mk"
