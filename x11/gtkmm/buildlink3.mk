# $NetBSD: buildlink3.mk,v 1.16 2009/04/15 03:54:04 reed Exp $

BUILDLINK_TREE+=	gtkmm

.if !defined(GTKMM_BUILDLINK3_MK)
GTKMM_BUILDLINK3_MK:=

# increase API_DEPENDS as a hack because now depends on pangomm
BUILDLINK_API_DEPENDS.gtkmm+=	gtkmm>=2.14.1
BUILDLINK_PKGSRCDIR.gtkmm?=	../../x11/gtkmm

.include "../../devel/pangomm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkmm
