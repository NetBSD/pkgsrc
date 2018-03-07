# $NetBSD: buildlink3.mk,v 1.4 2018/03/07 11:57:35 wiz Exp $

BUILDLINK_TREE+=	libFS

.if !defined(LIBFS_BUILDLINK3_MK)
LIBFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libFS+=	libFS>=1.0.0
BUILDLINK_PKGSRCDIR.libFS?=	../../x11/libFS

.include "../../x11/xorgproto/buildlink3.mk"
.endif # LIBFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libFS
