# $NetBSD: buildlink3.mk,v 1.7 2021/01/14 17:42:58 wiz Exp $

BUILDLINK_TREE+=	libXfixes

.if !defined(LIBXFIXES_BUILDLINK3_MK)
LIBXFIXES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXfixes+=	libXfixes>=4.0.1
BUILDLINK_PKGSRCDIR.libXfixes?=		../../x11/libXfixes

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # LIBXFIXES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXfixes
