# $NetBSD: buildlink3.mk,v 1.1 2004/02/26 17:29:24 jmmv Exp $
#
# This Makefile fragment is included by packages that use control-center.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CONTROL_CENTER_BUILDLINK3_MK:=	${CONTROL_CENTER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	control-center
.endif

.if !empty(CONTROL_CENTER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			control-center
BUILDLINK_DEPENDS.control-center+=		control-center>=1.4.0.4nb5
BUILDLINK_PKGSRCDIR.control-center?=		../../x11/controlcenter

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.endif # CONTROL_CENTER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
