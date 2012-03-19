# $NetBSD: buildlink3.mk,v 1.1 2012/03/19 19:44:03 markd Exp $

BUILDLINK_TREE+=	kde-runtime

.if !defined(KDE_RUNTIME_BUILDLINK3_MK)
KDE_RUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kde-runtime+=	kde-runtime4>=4.0.0
BUILDLINK_ABI_DEPENDS.kde-runtime?=	kde-runtime4>=4.5.4nb1
BUILDLINK_PKGSRCDIR.kde-runtime?=	../../x11/kde-runtime4

.include "../../x11/kdelibs4/buildlink3.mk"
.endif # KDE_RUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kde-runtime
