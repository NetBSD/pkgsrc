# $NetBSD: buildlink3.mk,v 1.1 2004/02/17 01:13:57 minskim Exp $
#
# This Makefile fragment is included by packages that use tidy.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TIDY_BUILDLINK3_MK:=	${TIDY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	tidy
.endif

.if !empty(TIDY_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			tidy
BUILDLINK_DEPENDS.tidy+=		tidy>=20031002
BUILDLINK_PKGSRCDIR.tidy?=		../../www/tidy

.endif # TIDY_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
