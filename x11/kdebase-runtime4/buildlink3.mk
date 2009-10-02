# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/02 19:30:13 markd Exp $

BUILDLINK_TREE+=	kdebase-runtime

.if !defined(KDEBASE_RUNTIME_BUILDLINK3_MK)
KDEBASE_RUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdebase-runtime+=	kdebase-runtime4>=4.0.0
BUILDLINK_ABI_DEPENDS.kdebase-runtime?=	kdebase-runtime4>=4.0.0nb1
BUILDLINK_PKGSRCDIR.kdebase-runtime?=	../../x11/kdebase-runtime4

.include "../../x11/kdelibs4/buildlink3.mk"
.endif # KDEBASE_RUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdebase-runtime
