# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 05:41:22 xtraeme Exp $
#
# This Makefile fragment is included by packages that use metacity.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
METACITY_BUILDLINK3_MK:=	${METACITY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	metacity
.endif

.if !empty(METACITY_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			metacity
BUILDLINK_DEPENDS.metacity+=		metacity>=2.6.3nb1
BUILDLINK_PKGSRCDIR.metacity?=		../../wm/metacity

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.endif # METACITY_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
