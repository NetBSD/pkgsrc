# $NetBSD: buildlink3.mk,v 1.1 2004/02/17 21:57:58 jmmv Exp $
#
# This Makefile fragment is included by packages that use gnome-mag.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME_MAG_BUILDLINK3_MK:=	${GNOME_MAG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-mag
.endif

.if !empty(GNOME_MAG_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome-mag
BUILDLINK_DEPENDS.gnome-mag?=		gnome-mag>=0.10.4nb1
BUILDLINK_PKGSRCDIR.gnome-mag?=		../../x11/gnome-mag

.include "../../devel/gettext-lib/buildlink3.mk"

.endif # GNOME_MAG_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
