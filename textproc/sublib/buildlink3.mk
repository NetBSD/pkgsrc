# $NetBSD: buildlink3.mk,v 1.21 2018/07/20 03:33:56 ryoon Exp $

BUILDLINK_TREE+=	sublib

.if !defined(SUBLIB_BUILDLINK3_MK)
SUBLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sublib+=	sublib>=0.9
BUILDLINK_ABI_DEPENDS.sublib+=	sublib>=0.9nb20
BUILDLINK_PKGSRCDIR.sublib?=	../../textproc/sublib

.include "../../lang/mono2/buildlink3.mk"
.endif # SUBLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-sublib
