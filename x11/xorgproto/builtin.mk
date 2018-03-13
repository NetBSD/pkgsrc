# $NetBSD: builtin.mk,v 1.1 2018/03/13 02:06:12 mrg Exp $

BUILTIN_PKG:=	xorgproto

PRE_XORGPROTO_LIST_MISSING = \
	applewmproto \
	dmxproto \
	lg3dproto \
	printproto \
	windowswmproto \
	xcalibrateproto \
	xf86rushproto
PRE_XORGPROTO_LIST = \
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
PRE_XORGPROTO_LIST += \
	xproto

BUILTIN_VERSION_SCRIPT.${BUILTIN_PKG}?= ${SED} -n -e 's/Version: 7\.0\.31/2018.1/p'

.for _p in ${PRE_XORGPROTO_LIST}
PKGCONFIG_FILE.xorgproto=	${X11BASE}/lib/pkgconfig/${_p}.pc
PKGCONFIG_FILE.xorgproto+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/${_p}.pc
PKGCONFIG_FILE.xorgproto+=	${X11BASE}/share/pkgconfig/${_p}.pc
.endfor

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
