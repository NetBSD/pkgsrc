# $NetBSD: buildlink3.mk,v 1.14 2023/11/08 13:21:31 wiz Exp $

BUILDLINK_TREE+=	libkscreen

.if !defined(LIBKSCREEN_BUILDLINK3_MK)
LIBKSCREEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkscreen+=	libkscreen>=5.6.3
BUILDLINK_ABI_DEPENDS.libkscreen?=	libkscreen>=5.24.6nb7
BUILDLINK_PKGSRCDIR.libkscreen?=	../../x11/libkscreen

.include "../../devel/kwayland/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# LIBKSCREEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkscreen
