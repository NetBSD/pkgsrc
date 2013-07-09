# $NetBSD: options.mk,v 1.3 2013/07/09 15:49:43 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-gtk2
PKG_SUPPORTED_OPTIONS=	py-numpy
PKG_SUGGESTED_OPTIONS=
# Enable py-numpy (which requires fortran support) by default on
# platforms supported by lang/g95.
.if (!empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64) || \
	!empty(MACHINE_ARCH:Mia64) || !empty(MACHINE_ARCH:Mpowerpc*) || \
	!empty(MACHINE_ARCH:Mhppa) || !empty(MACHINE_ARCH:Msparc*) || \
	!empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Mmips*))
# ...but disable it until lang/g95 issue is resolved.
#PKG_SUGGESTED_OPTIONS+=	py-numpy
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpy-numpy)
.include "../../math/py-numpy/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-numpy
.endif
