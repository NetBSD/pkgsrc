# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:45 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && !exists(${X11BASE}/lib/pkgconfig/xmu.pc)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libXmu

.if !defined(LIBXMU_BUILDLINK3_MK)
LIBXMU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXmu+=	libXmu>=1.0.0
BUILDLINK_PKGSRCDIR.libXmu?=	../../x11/libXmu

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXMU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXmu

.endif
