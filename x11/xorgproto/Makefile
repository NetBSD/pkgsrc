# $NetBSD: Makefile,v 1.6 2019/06/26 06:12:46 wiz Exp $

DISTNAME=		xorgproto-2018.4
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Various X headers from Xorg X11
LICENSE=		mit

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c

PKGCONFIG_OVERRIDE+=	applewmproto.pc.in
PKGCONFIG_OVERRIDE+=	bigreqsproto.pc.in
PKGCONFIG_OVERRIDE+=	compositeproto.pc.in
PKGCONFIG_OVERRIDE+=	damageproto.pc.in
PKGCONFIG_OVERRIDE+=	dmxproto.pc.in
PKGCONFIG_OVERRIDE+=	dri2proto.pc.in
PKGCONFIG_OVERRIDE+=	dri3proto.pc.in
PKGCONFIG_OVERRIDE+=	evieproto.pc.in
PKGCONFIG_OVERRIDE+=	fixesproto.pc.in
PKGCONFIG_OVERRIDE+=	fontcacheproto.pc.in
PKGCONFIG_OVERRIDE+=	fontsproto.pc.in
PKGCONFIG_OVERRIDE+=	glproto.pc.in
PKGCONFIG_OVERRIDE+=	inputproto.pc.in
PKGCONFIG_OVERRIDE+=	kbproto.pc.in
PKGCONFIG_OVERRIDE+=	lg3dproto.pc.in
PKGCONFIG_OVERRIDE+=	presentproto.pc.in
PKGCONFIG_OVERRIDE+=	printproto.pc.in
PKGCONFIG_OVERRIDE+=	randrproto.pc.in
PKGCONFIG_OVERRIDE+=	recordproto.pc.in
PKGCONFIG_OVERRIDE+=	renderproto.pc.in
PKGCONFIG_OVERRIDE+=	resourceproto.pc.in
PKGCONFIG_OVERRIDE+=	scrnsaverproto.pc.in
PKGCONFIG_OVERRIDE+=	trapproto.pc.in
PKGCONFIG_OVERRIDE+=	videoproto.pc.in
PKGCONFIG_OVERRIDE+=	windowswmproto.pc.in
PKGCONFIG_OVERRIDE+=	xcalibrateproto.pc.in
PKGCONFIG_OVERRIDE+=	xcmiscproto.pc.in
PKGCONFIG_OVERRIDE+=	xextproto.pc.in
PKGCONFIG_OVERRIDE+=	xf86bigfontproto.pc.in
PKGCONFIG_OVERRIDE+=	xf86dgaproto.pc.in
PKGCONFIG_OVERRIDE+=	xf86driproto.pc.in
PKGCONFIG_OVERRIDE+=	xf86miscproto.pc.in
PKGCONFIG_OVERRIDE+=	xf86rushproto.pc.in
PKGCONFIG_OVERRIDE+=	xf86vidmodeproto.pc.in
PKGCONFIG_OVERRIDE+=	xineramaproto.pc.in
PKGCONFIG_OVERRIDE+=	xproto.pc.in
PKGCONFIG_OVERRIDE+=	xproxymngproto.pc.in

.include "../../mk/bsd.pkg.mk"
