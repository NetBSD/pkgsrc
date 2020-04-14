# $NetBSD: builtin.mk,v 1.8 2020/04/14 19:30:46 wiz Exp $

BUILTIN_PKG:=	xorgproto

PRE_XORGPROTO_LIST_MISSING= \
	applewmproto \
	dmxproto \
	lg3dproto \
	printproto \
	windowswmproto \
	xcalibrateproto \
	xf86rushproto
PRE_XORGPROTO_LIST= \
	bigreqsproto \
	compositeproto \
	damageproto \
	dri2proto \
	dri3proto \
	evieproto \
	fixesproto \
	fontcacheproto \
	fontsproto \
	glproto \
	inputproto \
	kbproto \
	presentproto \
	randrproto \
	recordproto \
	renderproto \
	resourceproto \
	scrnsaverproto \
	trapproto \
	videoproto \
	xcmiscproto \
	xextproto \
	xf86bigfontproto \
	xf86dgaproto \
	xf86driproto \
	xf86miscproto \
	xf86vidmodeproto \
	xineramaproto \
	xproxymngproto

# Make xproto last, for the version matching.
PRE_XORGPROTO_LIST+= \
	xproto

# NetBSD-current (with modern xorgproto) has 7.0.32.
# NetBSD-8 has 7.0.31.
# NetBSD-7 has 7.0.26.
# NetBSD-6 has 7.0.22.
BUILTIN_VERSION_SCRIPT.${BUILTIN_PKG}?=	${SED} -n \
					-e 's/Version: 7\.0\.32/2018.4/p' \
					-e 's/Version: 7\.0\.31/2018.1/p' \
					-e 's/Version: 7\.0\.26/2017.1/p' \
					-e 's/Version: 7\.0\.22/2016.1/p'

.for _p in ${PRE_XORGPROTO_LIST}
PKGCONFIG_FILE.xorgproto=	${X11BASE}/lib/pkgconfig/${_p}.pc
PKGCONFIG_FILE.xorgproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/${_p}.pc
PKGCONFIG_FILE.xorgproto+=	${X11BASE}/share/pkgconfig/${_p}.pc
.endfor

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
