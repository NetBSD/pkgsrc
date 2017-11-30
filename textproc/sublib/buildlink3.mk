# $NetBSD: buildlink3.mk,v 1.19 2017/11/30 16:45:09 adam Exp $

BUILDLINK_TREE+=	sublib

.if !defined(SUBLIB_BUILDLINK3_MK)
SUBLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sublib+=	sublib>=0.9
BUILDLINK_ABI_DEPENDS.sublib+=	sublib>=0.9nb18
BUILDLINK_PKGSRCDIR.sublib?=	../../textproc/sublib

.include "../../lang/mono2/buildlink3.mk"
.endif # SUBLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-sublib
