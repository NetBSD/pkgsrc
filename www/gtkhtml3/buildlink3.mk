# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 03:59:51 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gtkhtml3.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKHTML3_BUILDLINK3_MK:=	${GTKHTML3_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkhtml3
.endif

.if !empty(GTKHTML3_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gtkhtml3
BUILDLINK_DEPENDS.gtkhtml3+=		gtkhtml3>=3.0.9nb5
BUILDLINK_PKGSRCDIR.gtkhtml3?=		../../www/gtkhtml3

.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gal2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"

.endif # GTKHTML3_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
