# $NetBSD: buildlink3.mk,v 1.9 2009/12/18 11:01:16 joerg Exp $

BUILDLINK_DEPMETHOD.clearsilver?=	build

BUILDLINK_TREE+=	clearsilver-base

.if !defined(CLEARSILVER_BUILDLINK3_MK)
CLEARSILVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clearsilver+=		clearsilver-base>=0.9.0
BUILDLINK_ABI_DEPENDS.clearsilver+=	clearsilver-base>=0.10.1
BUILDLINK_PKGSRCDIR.clearsilver?=	../../www/clearsilver-base
.endif # CLEARSILVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-clearsilver-base
