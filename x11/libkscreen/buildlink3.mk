# $NetBSD: buildlink3.mk,v 1.16 2023/11/14 03:53:46 gutteridge Exp $

BUILDLINK_TREE+=	libkscreen

.if !defined(LIBKSCREEN_BUILDLINK3_MK)
LIBKSCREEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkscreen+=	libkscreen>=5.27.9
BUILDLINK_PKGSRCDIR.libkscreen?=	../../x11/libkscreen

BUILDLINK_API_DEPENDS.kconfig+= kconfig>=5.102.0
.include "../../devel/kconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.kwayland+=        kwayland>=5.102.0
.include "../../devel/kwayland/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif	# LIBKSCREEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkscreen
