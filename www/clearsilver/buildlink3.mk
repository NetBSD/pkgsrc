# $NetBSD: buildlink3.mk,v 1.13 2023/08/14 05:25:28 wiz Exp $

BUILDLINK_TREE+=	clearsilver

.if !defined(CLEARSILVER_BUILDLINK3_MK)
CLEARSILVER_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.clearsilver?=	build

BUILDLINK_API_DEPENDS.clearsilver+=	clearsilver-base>=0.9.0
BUILDLINK_ABI_DEPENDS.clearsilver+=	clearsilver>=0.10.5nb19
BUILDLINK_PKGSRCDIR.clearsilver?=	../../www/clearsilver-base
.endif # CLEARSILVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-clearsilver
