# $NetBSD: options.mk,v 1.2 2005/01/24 17:24:08 hira Exp $

_COMMONCARDDRIVERS=	apm ark ati chips cirrus cyrix dummy glint i128 mga \
			neomagic nv rendition s3 s3virge savage siliconmotion \
			sis tdfx tga trident tseng vesa vga
_NOTX86_64CARDDRIVERS=	i740 i810 imstt newport nsc via vmware
_LINUXCARDDRIVERS=	fbdev v4l

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
PKG_DEFAULT_OPTIONS=	${PKG_SUPPORTED_OPTIONS}
.include "../../mk/bsd.options.mk"

.for _drv in ${PKG_OPTIONS}
PLIST_SUBST+=		CARDDRIVER.${_drv}=
.endfor

.for _drv in ${_ALLCARDDRIVERS}
.  if empty(PLIST_SUBST:MCARDDRIVER\.${_drv}=)
PLIST_SUBST+=		CARDDRIVER.${_drv}="@comment "
.  endif
.endfor

CARDDRIVERS=		${PKG_OPTIONS}
