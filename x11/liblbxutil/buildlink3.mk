# $NetBSD: buildlink3.mk,v 1.5 2015/10/22 14:34:45 tnn Exp $

BUILDLINK_TREE+=	liblbxutil

.if !defined(LIBLBXUTIL_BUILDLINK3_MK)
LIBLBXUTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblbxutil+=	liblbxutil>=1.1.0nb1
BUILDLINK_PKGSRCDIR.liblbxutil?=	../../x11/liblbxutil

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif	# LIBLBXUTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblbxutil
