# $NetBSD: options.mk,v 1.1 2005/01/24 10:57:27 hira Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xorg-server
PKG_SUPPORTED_OPTIONS!=	${X11BASE}/bin/imake -I${X11BASE}/lib/X11/config \
			    -f ${FILESDIR}/Imakefile.drivers -s - | \
			    ${EGREP} "^CARDDRIVERS=" | \
			    ${AWK} '{$$1=""; print $$0}'
PKG_DEFAULT_OPTIONS=	${PKG_SUPPORTED_OPTIONS}
.include "../../mk/bsd.options.mk"

ALLCARDDRIVERS=		apm ark ati chips cirrus cyrix dummy fbdev glint i128 \
			i740 i810 imstt mga neomagic newport nsc nv rendition \
			rendition s3 s3virge savage siliconmotion sis tdfx tga \
			trident tseng v4l vesa vga via vmware

.for _drv in ${PKG_OPTIONS}
PLIST_SUBST+=		CARDDRIVER.${_drv}=
.endfor

.for _drv in ${ALLCARDDRIVERS}
.  if empty(PLIST_SUBST:MCARDDRIVER\.${_drv}=)
PLIST_SUBST+=		CARDDRIVER.${_drv}="@comment "
.  endif
.endfor

CARDDRIVERS=		${PKG_OPTIONS}
