# $NetBSD: buildlink3.mk,v 1.17 2020/03/10 22:09:10 wiz Exp $

BUILDLINK_TREE+=	kxmlgui

.if !defined(KXMLGUI_BUILDLINK3_MK)
KXMLGUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kxmlgui+=	kxmlgui>=5.19.0
BUILDLINK_ABI_DEPENDS.kxmlgui?=	kxmlgui>=5.66.0nb2
BUILDLINK_PKGSRCDIR.kxmlgui?=	../../x11/kxmlgui

.include "../../misc/attica-qt5/buildlink3.mk"
.include "../../x11/kglobalaccel/buildlink3.mk"
.include "../../x11/ktextwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KXMLGUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-kxmlgui
