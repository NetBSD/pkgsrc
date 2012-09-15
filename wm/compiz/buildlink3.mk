# $NetBSD: buildlink3.mk,v 1.16 2012/09/15 10:06:42 obache Exp $

BUILDLINK_TREE+=	compiz

.if !defined(COMPIZ_BUILDLINK3_MK)
COMPIZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiz+=	compiz>=0.6.2
BUILDLINK_ABI_DEPENDS.compiz+=	compiz>=0.8.4nb23
BUILDLINK_PKGSRCDIR.compiz?=	../../wm/compiz

.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif # COMPIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiz
