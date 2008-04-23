# $NetBSD: buildlink3.mk,v 1.1 2008/04/23 18:34:52 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
COMPIZ_BUILDLINK3_MK:=	${COMPIZ_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	compiz
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncompiz}
BUILDLINK_PACKAGES+=	compiz
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}compiz

.if ${COMPIZ_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.compiz+=	compiz>=0.6.2
BUILDLINK_PKGSRCDIR.compiz?=	../../wm/compiz
.endif	# COMPIZ_BUILDLINK3_MK


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

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
