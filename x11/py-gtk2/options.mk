# $NetBSD: options.mk,v 1.1 2012/11/30 12:32:50 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-gtk2
PKG_SUPPORTED_OPTIONS=	py-numpy
.if (!empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64) || \
	!empty(MACHINE_ARCH:Mamd64) || \
	!empty(MACHINE_ARCH:Mia64) || !empty(MACHINE_ARCH:Mpowerpc*) || \
	!empty(MACHINE_ARCH:Mhppa) || !empty(MACHINE_ARCH:Msparc*) || \
	!empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Mmips*))
PKG_SUGGESTED_OPTIONS=	py-numpy
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpy-numpy)
.include "../../math/py-numpy/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-numpy
.endif
