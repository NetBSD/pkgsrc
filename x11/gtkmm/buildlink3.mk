# $NetBSD: buildlink3.mk,v 1.54 2022/06/28 11:37:54 wiz Exp $

BUILDLINK_TREE+=	gtkmm

.if !defined(GTKMM_BUILDLINK3_MK)
GTKMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.22.0
BUILDLINK_ABI_DEPENDS.gtkmm+=	gtkmm>=2.24.5nb16
BUILDLINK_PKGSRCDIR.gtkmm?=	../../x11/gtkmm

.include "../../devel/atkmm/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkmm
