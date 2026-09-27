# $NetBSD: buildlink3.mk,v 1.39 2026/09/27 11:39:27 tnn Exp $

BUILDLINK_TREE+=	lxqt-globalkeys

.if !defined(LXQT_GLOBALKEYS_BUILDLINK3_MK)
LXQT_GLOBALKEYS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lxqt-globalkeys+=	lxqt-globalkeys>=2.0.0
BUILDLINK_ABI_DEPENDS.lxqt-globalkeys?=	lxqt-globalkeys>=2.4.0nb3
BUILDLINK_PKGSRCDIR.lxqt-globalkeys?=	../../x11/lxqt-globalkeys

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.endif	# LXQT_GLOBALKEYS_BUILDLINK3_MK

BUILDLINK_TREE+=	-lxqt-globalkeys
