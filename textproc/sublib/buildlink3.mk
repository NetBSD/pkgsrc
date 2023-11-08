# $NetBSD: buildlink3.mk,v 1.32 2023/11/08 13:21:10 wiz Exp $

BUILDLINK_TREE+=	sublib

.if !defined(SUBLIB_BUILDLINK3_MK)
SUBLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sublib+=	sublib>=0.9
BUILDLINK_ABI_DEPENDS.sublib+=	sublib>=0.9nb32
BUILDLINK_PKGSRCDIR.sublib?=	../../textproc/sublib

.include "../../lang/mono/buildlink3.mk"
.endif # SUBLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-sublib
