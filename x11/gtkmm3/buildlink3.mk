# $NetBSD: buildlink3.mk,v 1.26 2022/06/28 11:37:54 wiz Exp $

BUILDLINK_TREE+=	gtkmm3

.if !defined(GTKMM3_BUILDLINK3_MK)
GTKMM3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkmm3+=	gtkmm3>=3.4.2
BUILDLINK_ABI_DEPENDS.gtkmm3?=	gtkmm3>=3.24.5nb3
BUILDLINK_PKGSRCDIR.gtkmm3?=	../../x11/gtkmm3

.include "../../devel/atkmm/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# GTKMM3_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkmm3
