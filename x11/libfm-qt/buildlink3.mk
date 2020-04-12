# $NetBSD: buildlink3.mk,v 1.4 2020/04/12 08:28:12 adam Exp $

BUILDLINK_TREE+=	libfm-qt

.if !defined(LIBFM_QT_BUILDLINK3_MK)
LIBFM_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm-qt+=	libfm-qt>=0.14.1
BUILDLINK_ABI_DEPENDS.libfm-qt?=		libfm-qt>=0.14.1nb3
BUILDLINK_PKGSRCDIR.libfm-qt?=		../../x11/libfm-qt

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.endif	# LIBFM_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm-qt
