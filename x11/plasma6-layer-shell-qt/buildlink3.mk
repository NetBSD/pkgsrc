# $NetBSD: buildlink3.mk,v 1.2 2024/11/01 00:54:23 wiz Exp $

BUILDLINK_TREE+=	plasma6-layer-shell-qt

.if !defined(PLASMA6_LAYER_SHELL_QT_BUILDLINK3_MK)
PLASMA6_LAYER_SHELL_QT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-layer-shell-qt+=	plasma6-layer-shell-qt>=6.0.5
BUILDLINK_ABI_DEPENDS.plasma6-layer-shell-qt?=	plasma6-layer-shell-qt>=6.0.5nb1
BUILDLINK_PKGSRCDIR.plasma6-layer-shell-qt?=	../../x11/plasma6-layer-shell-qt

.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif	# PLASMA6_LAYER_SHELL_QT_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-layer-shell-qt
