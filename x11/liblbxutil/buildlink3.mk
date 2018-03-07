# $NetBSD: buildlink3.mk,v 1.6 2018/03/07 11:57:38 wiz Exp $

BUILDLINK_TREE+=	liblbxutil

.if !defined(LIBLBXUTIL_BUILDLINK3_MK)
LIBLBXUTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblbxutil+=	liblbxutil>=1.1.0nb1
BUILDLINK_PKGSRCDIR.liblbxutil?=	../../x11/liblbxutil

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.endif	# LIBLBXUTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblbxutil
