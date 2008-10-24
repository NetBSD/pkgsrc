# $NetBSD: buildlink3.mk,v 1.8 2008/10/24 20:51:11 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_SHARP_BUILDLINK3_MK:=	${GNOME_SHARP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnome-sharp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-sharp}
BUILDLINK_PACKAGES+=	gnome-sharp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-sharp

.if ${GNOME_SHARP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnome-sharp+=	gnome-sharp>=2.24.0
BUILDLINK_PKGSRCDIR.gnome-sharp?=	../../x11/gnome-sharp
.endif	# GNOME_SHARP_BUILDLINK3_MK

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
