# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/02 19:43:39 markd Exp $

BUILDLINK_TREE+=	kdebase4

.if !defined(KDEBASE4_BUILDLINK3_MK)
KDEBASE4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdebase4+=	kdebase4>=4.1.85
BUILDLINK_PKGSRCDIR.kdebase4?=	../../x11/kdebase4
.endif # KDEBASE4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdebase4
