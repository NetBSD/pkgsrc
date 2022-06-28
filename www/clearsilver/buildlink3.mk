# $NetBSD: buildlink3.mk,v 1.12 2022/06/28 11:37:03 wiz Exp $

BUILDLINK_TREE+=	clearsilver

.if !defined(CLEARSILVER_BUILDLINK3_MK)
CLEARSILVER_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.clearsilver?=	build

BUILDLINK_API_DEPENDS.clearsilver+=	clearsilver-base>=0.9.0
BUILDLINK_ABI_DEPENDS.clearsilver+=	clearsilver>=0.10.5nb16
BUILDLINK_PKGSRCDIR.clearsilver?=	../../www/clearsilver-base
.endif # CLEARSILVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-clearsilver
