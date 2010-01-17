# $NetBSD: buildlink3.mk,v 1.2 2010/01/17 12:02:56 wiz Exp $

BUILDLINK_TREE+=	kdebase-workspace

.if !defined(KDEBASE_WORKSPACE_BUILDLINK3_MK)
KDEBASE_WORKSPACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdebase-workspace+=	kdebase-workspace4>=4.0.0
BUILDLINK_ABI_DEPENDS.kdebase-workspace?=	kdebase-workspace4>=4.3.4nb1
BUILDLINK_PKGSRCDIR.kdebase-workspace?=	../../x11/kdebase-workspace4

.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.endif # KDEBASE_WORKSPACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdebase-workspace
