# $NetBSD: Makefile,v 1.16 2004/05/13 04:29:13 xtraeme Exp $
#

DISTNAME=	fluxbox-0.9.9
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
.include "../../fonts/Xft2/buildlink3.mk"
.elseif
CONFIGURE_ARGS+=	--disable-xft
.endif

.include "../../mk/bsd.pkg.mk"
