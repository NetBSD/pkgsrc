# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:34 joerg Exp $

BUILDLINK_TREE+=	blackbox70

.if !defined(BLACKBOX70_BUILDLINK3_MK)
BLACKBOX70_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.blackbox70+=	blackbox70>=0.70.0
BUILDLINK_ABI_DEPENDS.blackbox70+=	blackbox70>=0.70.0
BUILDLINK_PKGSRCDIR.blackbox70?=	../../wm/blackbox70

.include "../../x11/libX11/buildlink3.mk"
.endif # BLACKBOX70_BUILDLINK3_MK

BUILDLINK_TREE+=	-blackbox70
