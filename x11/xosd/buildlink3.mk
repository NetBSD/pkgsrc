# $NetBSD: buildlink3.mk,v 1.1 2004/02/19 15:00:38 wiz Exp $
#
# This Makefile fragment is included by packages that use xosd.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XOSD_BUILDLINK3_MK:=	${XOSD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xosd
.endif

.if !empty(XOSD_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			xosd
BUILDLINK_DEPENDS.xosd+=		xosd>=2.2.5
BUILDLINK_PKGSRCDIR.xosd?=		../../x11/xosd

.endif # XOSD_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
