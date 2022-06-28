# $NetBSD: buildlink3.mk,v 1.18 2022/06/28 11:37:55 wiz Exp $

BUILDLINK_TREE+=	liblxqt

.if !defined(LIBLXQT_BUILDLINK3_MK)
LIBLXQT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblxqt+=	liblxqt>=1.1.0
BUILDLINK_ABI_DEPENDS.liblxqt?=	liblxqt>=1.1.0nb2
BUILDLINK_PKGSRCDIR.liblxqt?=	../../x11/liblxqt

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/libqtxdg/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../security/polkit-qt5/buildlink3.mk"
.endif	# LIBLXQT_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblxqt
