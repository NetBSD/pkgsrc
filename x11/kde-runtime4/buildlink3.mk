# $NetBSD: buildlink3.mk,v 1.50 2022/04/18 19:10:14 adam Exp $

BUILDLINK_TREE+=	kde-runtime

.if !defined(KDE_RUNTIME_BUILDLINK3_MK)
KDE_RUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kde-runtime+=	kde-runtime4>=4.0.0
BUILDLINK_ABI_DEPENDS.kde-runtime+=	kde-runtime4>=15.12.0nb65
BUILDLINK_PKGSRCDIR.kde-runtime?=	../../x11/kde-runtime4

.include "../../x11/kdelibs4/buildlink3.mk"
.endif # KDE_RUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kde-runtime
