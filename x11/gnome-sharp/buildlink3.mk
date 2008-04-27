# $NetBSD: buildlink3.mk,v 1.5 2008/04/27 23:03:53 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_SHARP_BUILDLINK3_MK:=	${GNOME_SHARP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnome-sharp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-sharp}
BUILDLINK_PACKAGES+=	gnome-sharp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-sharp

.if ${GNOME_SHARP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnome-sharp+=	gnome-sharp>=2.16.1
BUILDLINK_ABI_DEPENDS.gnome-sharp?=	gnome-sharp>=2.16.1nb1
BUILDLINK_PKGSRCDIR.gnome-sharp?=	../../x11/gnome-sharp
.endif	# GNOME_SHARP_BUILDLINK3_MK

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../lang/monodoc/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
