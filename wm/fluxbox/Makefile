# $NetBSD: Makefile,v 1.13 2003/08/08 11:12:31 hubertf Exp $
#

DISTNAME=	fluxbox-0.9.4
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxbox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://fluxbox.sourceforge.net/
COMMENT=	Window Manager for X based on Blackbox

DEPENDS=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_GCC_SHLIB=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

FLUXBOX_USE_XINERAMA?=	NO
.if !empty(FLUXBOX_USE_XINERAMA:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-xinerama
.endif

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
.include "../../fonts/Xft2/buildlink2.mk"
.elseif
CONFIGURE_ARGS+=	--disable-xft
.endif

.include "../../mk/bsd.pkg.mk"
