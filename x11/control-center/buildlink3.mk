# $NetBSD: buildlink3.mk,v 1.2 2006/01/24 07:32:50 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CONTROL_CENTER_BUILDLINK3_MK:=	${CONTROL_CENTER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	control-center
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncontrol-center}
BUILDLINK_PACKAGES+=	control-center

.if !empty(CONTROL_CENTER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.control-center+=	control-center>=1.4.0.4nb9
BUILDLINK_RECOMMENDED.control-center+=	control-center>=1.4.0.5nb1
BUILDLINK_PKGSRCDIR.control-center?=	../../x11/control-center
.endif	# CONTROL_CENTER_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
