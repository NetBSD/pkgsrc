# $NetBSD: buildlink3.mk,v 1.6 2018/03/07 11:57:36 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && \
	!exists(${X11BASE}/lib/pkgconfig/xfixes.pc) && \
	!exists(${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/xfixes.pc)
.include "../../x11/Xfixes/buildlink3.mk"
.else

BUILDLINK_TREE+=	libXfixes

.  if !defined(LIBXFIXES_BUILDLINK3_MK)
LIBXFIXES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXfixes+=	libXfixes>=4.0.1
BUILDLINK_PKGSRCDIR.libXfixes?=		../../x11/libXfixes

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.  endif # LIBXFIXES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXfixes

.endif
