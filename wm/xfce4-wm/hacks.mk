# $NetBSD: hacks.mk,v 1.1 2020/10/16 06:21:13 nia Exp $

.if !defined(XFCE4_WM_HACKS_MK)
XFCE4_WM_HACKS_MK=	defined

# Unfortunately, the check in xfwm's configure script simply determines
# whether XRes is available, not its version.
# It's using XRes 1.2 features, but the base version installed in NetBSD 8.x
# is too old to support that.
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[5678].*) && \
    ${X11_TYPE} == "native"
PKG_HACKS+=	old-netbsd-xres
CONFIGURE_ENV+=	ac_cv_lib_XRes_XResQueryClients=no
.endif

.endif # XFCE4_WM_HACKS_MK
