# $NetBSD: buildlink3.mk,v 1.10 2018/11/14 22:22:33 kleink Exp $
#

BUILDLINK_TREE+=	marco

.if !defined(MARCO_BUILDLINK3_MK)
MARCO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marco+=	marco>=1.8.2
BUILDLINK_ABI_DEPENDS.marco+=	marco>=1.20.1nb2
BUILDLINK_PKGSRCDIR.marco?=	../../wm/marco

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.endif	# MARCO_BUILDLINK3_MK

BUILDLINK_TREE+=	-marco
