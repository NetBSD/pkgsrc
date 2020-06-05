# $NetBSD: buildlink3.mk,v 1.41 2020/06/05 12:49:01 jperkin Exp $

BUILDLINK_TREE+=	kde-workspace

.if !defined(KDE_WORKSPACE_BUILDLINK3_MK)
KDE_WORKSPACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kde-workspace+=	kde-workspace4>=4.0.0
BUILDLINK_ABI_DEPENDS.kde-workspace+=	kde-workspace4>=4.11.22nb31
BUILDLINK_PKGSRCDIR.kde-workspace?=	../../x11/kde-workspace4

.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.endif # KDE_WORKSPACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kde-workspace
