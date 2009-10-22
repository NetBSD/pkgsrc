# $NetBSD: buildlink3.mk,v 1.18 2009/10/22 08:22:02 adam Exp $

BUILDLINK_TREE+=	gtkmm

.if !defined(GTKMM_BUILDLINK3_MK)
GTKMM_BUILDLINK3_MK:=

# increase API_DEPENDS as a hack because now depends on pangomm
BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.18.2
BUILDLINK_ABI_DEPENDS.gtkmm?=	gtkmm>=2.18.2
BUILDLINK_PKGSRCDIR.gtkmm?=	../../x11/gtkmm

.include "../../devel/pangomm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkmm
