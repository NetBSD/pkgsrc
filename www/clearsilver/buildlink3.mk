# $NetBSD: buildlink3.mk,v 1.11 2013/04/06 13:46:34 rodent Exp $

BUILDLINK_TREE+=	clearsilver

.if !defined(CLEARSILVER_BUILDLINK3_MK)
CLEARSILVER_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.clearsilver?=	build

BUILDLINK_API_DEPENDS.clearsilver+=	clearsilver-base>=0.9.0
BUILDLINK_ABI_DEPENDS.clearsilver+=	clearsilver-base>=0.10.1
BUILDLINK_PKGSRCDIR.clearsilver?=	../../www/clearsilver-base
.endif # CLEARSILVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-clearsilver
