# $NetBSD: buildlink3.mk,v 1.69 2025/09/27 09:57:40 wiz Exp $

BUILDLINK_TREE+=	kde-runtime

.if !defined(KDE_RUNTIME_BUILDLINK3_MK)
KDE_RUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kde-runtime+=	kde-runtime4>=4.0.0
BUILDLINK_ABI_DEPENDS.kde-runtime+=	kde-runtime4>=15.12.0nb112
BUILDLINK_PKGSRCDIR.kde-runtime?=	../../x11/kde-runtime4

.include "../../x11/kdelibs4/buildlink3.mk"
.endif # KDE_RUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kde-runtime
