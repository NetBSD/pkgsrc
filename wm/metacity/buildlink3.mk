# $NetBSD: buildlink3.mk,v 1.41 2014/05/05 00:48:25 ryoon Exp $

BUILDLINK_TREE+=	metacity

.if !defined(METACITY_BUILDLINK3_MK)
METACITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.metacity+=	metacity>=2.8.5
BUILDLINK_ABI_DEPENDS.metacity+=	metacity>=2.34.1nb16
BUILDLINK_PKGSRCDIR.metacity?=	../../wm/metacity

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.endif # METACITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-metacity
