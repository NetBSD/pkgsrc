# $NetBSD: buildlink3.mk,v 1.31 2024/11/01 00:54:20 wiz Exp $

BUILDLINK_TREE+=	liblxqt

.if !defined(LIBLXQT_BUILDLINK3_MK)
LIBLXQT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblxqt+=	liblxqt>=2.0.0
BUILDLINK_ABI_DEPENDS.liblxqt?=	liblxqt>=2.0.0nb1
BUILDLINK_PKGSRCDIR.liblxqt?=	../../x11/liblxqt

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/libqtxdg/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../security/polkit-qt6/buildlink3.mk"
.endif	# LIBLXQT_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblxqt
