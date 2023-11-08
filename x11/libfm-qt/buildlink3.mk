# $NetBSD: buildlink3.mk,v 1.26 2023/11/08 13:21:31 wiz Exp $

BUILDLINK_TREE+=	libfm-qt

.if !defined(LIBFM_QT_BUILDLINK3_MK)
LIBFM_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm-qt+=	libfm-qt>=1.3.0
BUILDLINK_ABI_DEPENDS.libfm-qt?=		libfm-qt>=1.3.0nb4
BUILDLINK_PKGSRCDIR.libfm-qt?=		../../x11/libfm-qt

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.endif	# LIBFM_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm-qt
