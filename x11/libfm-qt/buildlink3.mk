# $NetBSD: buildlink3.mk,v 1.42 2026/04/28 07:59:10 pin Exp $

BUILDLINK_TREE+=	libfm-qt

.if !defined(LIBFM_QT_BUILDLINK3_MK)
LIBFM_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm-qt+=	libfm-qt>=2.3.0
BUILDLINK_ABI_DEPENDS.libfm-qt?=	libfm-qt>=2.4.0
BUILDLINK_PKGSRCDIR.libfm-qt?=		../../x11/libfm-qt

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.endif	# LIBFM_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm-qt
