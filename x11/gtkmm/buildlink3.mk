# $NetBSD: buildlink3.mk,v 1.34 2013/02/16 11:18:29 wiz Exp $

BUILDLINK_TREE+=	gtkmm

.if !defined(GTKMM_BUILDLINK3_MK)
GTKMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.22.0
BUILDLINK_ABI_DEPENDS.gtkmm+=	gtkmm>=2.24.2nb9
BUILDLINK_PKGSRCDIR.gtkmm?=	../../x11/gtkmm

.include "../../devel/atkmm/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkmm
