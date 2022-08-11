# $NetBSD: buildlink3.mk,v 1.4 2022/08/11 05:09:21 gutteridge Exp $

BUILDLINK_TREE+=	swc

.if !defined(SWC_BUILDLINK3_MK)
SWC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swc+=	swc>=0.0.0.20191211
BUILDLINK_ABI_DEPENDS.swc?=	swc>=0.0.0.20200228nb3
BUILDLINK_PKGSRCDIR.swc?=	../../wm/swc

.include "../../devel/wayland/buildlink3.mk"
.include "../../graphics/wld/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif	# SWC_BUILDLINK3_MK

BUILDLINK_TREE+=	-swc
