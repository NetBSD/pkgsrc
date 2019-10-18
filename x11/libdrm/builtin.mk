# $NetBSD: builtin.mk,v 1.5 2019/10/18 09:04:16 nia Exp $

BUILTIN_PKG:=	libdrm

.for pcfile in libdrm libdrm_amdgpu libdrm_intel libdrm_nouveau libdrm_radeon
PKGCONFIG_FILE.libdrm+=	${X11BASE}/lib/pkgconfig/${pcfile}.pc
PKGCONFIG_FILE.libdrm+=	${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/${pcfile}.pc
.endfor

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
.include "../../mk/x11.builtin.mk"
