# $NetBSD: options.mk,v 1.5 2005/12/02 17:51:50 wiz Exp $

_COMMONCARDDRIVERS=	xorg-server-apm xorg-server-ark xorg-server-ati \
			xorg-server-chips xorg-server-cirrus \
			xorg-server-cyrix xorg-server-dummy \
			xorg-server-glint xorg-server-i128 \
			xorg-server-mga xorg-server-neomagic \
			xorg-server-nv xorg-server-rendition \
			xorg-server-s3 xorg-server-s3virge \
			xorg-server-savage xorg-server-siliconmotion \
			xorg-server-sis xorg-server-tdfx \
			xorg-server-tga xorg-server-trident \
			xorg-server-tseng xorg-server-vesa \
			xorg-server-vga
_NOTX86_64CARDDRIVERS=	xorg-server-i740 xorg-server-i810 \
			xorg-server-imstt xorg-server-newport \
			xorg-server-nsc xorg-server-via \
			xorg-server-vmware
_LINUXCARDDRIVERS=	xorg-server-fbdev xorg-server-v4l

_ALLCARDDRIVERS=	${_COMMONCARDDRIVERS} ${_NOTX86_64CARDDRIVERS} \
			${_LINUXCARDDRIVERS}

_OSCARDDRIVERS=		# defined

# Not tested with the other x86_64 platforms.
.if empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
_OSCARDDRIVERS+=	${_NOTX86_64CARDDRIVERS}
.endif

.if ${OPSYS} == "Linux"
_OSCARDDRIVERS+=	${_LINUXCARDDRIVERS}
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.xorg-server
PKG_SUPPORTED_OPTIONS=	${_COMMONCARDDRIVERS} ${_OSCARDDRIVERS}
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS}

# remove legacy handling after 2005Q4
.for _drv in ${_ALLCARDDRIVERS}
PKG_OPTIONS_LEGACY_OPTS+=	${_drv:S/xorg-server-//}:${_drv}
.endfor

.include "../../mk/bsd.options.mk"

.for _drv in ${PKG_OPTIONS}
PLIST_SUBST+=		CARDDRIVER.${_drv}=
.endfor

.for _drv in ${_ALLCARDDRIVERS}
.  if empty(PKG_OPTIONS:M${_drv})
PLIST_SUBST+=		CARDDRIVER.${_drv}="@comment "
.  endif
.endfor

CARDDRIVERS=		${PKG_OPTIONS:S/xorg-server-//g}
