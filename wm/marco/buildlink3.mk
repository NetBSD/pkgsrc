# $NetBSD: buildlink3.mk,v 1.32 2026/01/27 08:40:45 wiz Exp $

BUILDLINK_TREE+=	marco

.if !defined(MARCO_BUILDLINK3_MK)
MARCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marco+=	marco>=1.26.2nb12
BUILDLINK_ABI_DEPENDS.marco?=	marco>=1.26.2nb13
BUILDLINK_PKGSRCDIR.marco?=	../../wm/marco

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# MARCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-marco
