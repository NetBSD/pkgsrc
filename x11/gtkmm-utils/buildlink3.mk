# $NetBSD: buildlink3.mk,v 1.35 2023/01/03 17:36:36 wiz Exp $

BUILDLINK_TREE+=	gtkmm-utils

.if !defined(GTKMM_UTILS_BUILDLINK3_MK)
GTKMM_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkmm-utils+=	gtkmm-utils>=0.4.1
BUILDLINK_ABI_DEPENDS.gtkmm-utils+=	gtkmm-utils>=0.4.1nb34
BUILDLINK_PKGSRCDIR.gtkmm-utils?=	../../x11/gtkmm-utils

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif # GTKMM_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkmm-utils
