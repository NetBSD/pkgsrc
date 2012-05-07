# $NetBSD: buildlink3.mk,v 1.5 2012/05/07 02:45:48 dholland Exp $

BUILDLINK_TREE+=	xtrans

.if !defined(XTRANS_BUILDLINK3_MK)
XTRANS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xtrans+=		xtrans>=1.0.3
BUILDLINK_PKGSRCDIR.xtrans?=		../../x11/xtrans
BUILDLINK_DEPMETHOD.xtrans?=		build
.endif # XTRANS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xtrans
