# $NetBSD: buildlink3.mk,v 1.5 2010/04/09 08:46:32 tnn Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libXi

.if !defined(LIBXI_BUILDLINK3_MK)
LIBXI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXi+=	libXi>=1.3
BUILDLINK_PKGSRCDIR.libXi?=	../../x11/libXi

.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXi

.endif
