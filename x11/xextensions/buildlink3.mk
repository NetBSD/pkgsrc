# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/04/13 09:58:07 xtraeme Exp $
#
# This Makefile fragment is included by packages that use xextensions.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XEXTENSIONS_BUILDLINK3_MK:=	${XEXTENSIONS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xextensions
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxextensions}
BUILDLINK_PACKAGES+=	xextensions

.if !empty(XEXTENSIONS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xextensions?=		xextensions>=1.0
BUILDLINK_PKGSRCDIR.xextensions?=	../../x11/xextensions
.endif # XEXTENSIONS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
