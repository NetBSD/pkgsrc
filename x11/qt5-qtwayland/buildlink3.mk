# $NetBSD: buildlink3.mk,v 1.8 2025/12/22 13:24:44 adam Exp $

BUILDLINK_TREE+=	qt5-qtwayland

.if !defined(QT5_QTWAYLAND_BUILDLINK3_MK)
QT5_QTWAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qtwayland+=	qt5-qtwayland>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qtwayland+=	qt5-qtwayland>=5.15.18
BUILDLINK_PKGSRCDIR.qt5-qtwayland?=	../../x11/qt5-qtwayland

BUILDLINK_INCDIRS.qt5-qtwayland+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qtwayland+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qtwayland+=	qt5/plugins

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"

.endif	# QT5_QTWAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qtwayland
