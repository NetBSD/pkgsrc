# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:44 joerg Exp $

BUILDLINK_TREE+=	libXau

.if !defined(LIBXAU_BUILDLINK3_MK)
LIBXAU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXau+=	libXau>=1.0
BUILDLINK_PKGSRCDIR.libXau?=	../../x11/libXau

.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXAU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXau
