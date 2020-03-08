# $NetBSD: buildlink3.mk,v 1.50 2020/03/08 16:48:23 wiz Exp $

BUILDLINK_TREE+=	gtkmm

.if !defined(GTKMM_BUILDLINK3_MK)
GTKMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.22.0
BUILDLINK_ABI_DEPENDS.gtkmm+=	gtkmm>=2.24.5nb10
BUILDLINK_PKGSRCDIR.gtkmm?=	../../x11/gtkmm

.include "../../devel/atkmm/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkmm
