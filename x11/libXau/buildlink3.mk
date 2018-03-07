# $NetBSD: buildlink3.mk,v 1.5 2018/03/07 11:57:35 wiz Exp $

BUILDLINK_TREE+=	libXau

.if !defined(LIBXAU_BUILDLINK3_MK)
LIBXAU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXau+=	libXau>=1.0
BUILDLINK_PKGSRCDIR.libXau?=	../../x11/libXau

.include "../../x11/xorgproto/buildlink3.mk"
.endif # LIBXAU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXau
