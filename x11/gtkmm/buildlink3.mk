# $NetBSD: buildlink3.mk,v 1.17 2009/08/26 19:56:54 sno Exp $

BUILDLINK_TREE+=	gtkmm

.if !defined(GTKMM_BUILDLINK3_MK)
GTKMM_BUILDLINK3_MK:=

# increase API_DEPENDS as a hack because now depends on pangomm
BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.14.1
BUILDLINK_ABI_DEPENDS.gtkmm?=	gtkmm>=2.16.0nb1
BUILDLINK_PKGSRCDIR.gtkmm?=	../../x11/gtkmm

.include "../../devel/pangomm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkmm
