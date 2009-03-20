# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:43 joerg Exp $

BUILDLINK_TREE+=	libFS

.if !defined(LIBFS_BUILDLINK3_MK)
LIBFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libFS+=	libFS>=1.0.0
BUILDLINK_PKGSRCDIR.libFS?=	../../x11/libFS

.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libFS
