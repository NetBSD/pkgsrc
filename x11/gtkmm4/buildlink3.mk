# $NetBSD: buildlink3.mk,v 1.17 2026/09/02 19:05:10 wiz Exp $

BUILDLINK_TREE+=	gtkmm4

.if !defined(GTKMM4_BUILDLINK3_MK)
GTKMM4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkmm4+=	gtkmm4>=4.2.0
BUILDLINK_ABI_DEPENDS.gtkmm4+=	gtkmm4>=4.20.0nb3
BUILDLINK_PKGSRCDIR.gtkmm4?=	../../x11/gtkmm4

.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/glibmm2.68/buildlink3.mk"
.include "../../devel/pangomm2.48/buildlink3.mk"
.include "../../graphics/cairomm1.16/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.endif	# GTKMM4_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkmm4
