# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 17:27:30 joerg Exp $
#
# This Makefile fragment is included by packages that use libICE.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBICE_BUILDLINK3_MK:=	${LIBICE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libICE
.endif

.if !empty(LIBICE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libICE
BUILDLINK_API_DEPENDS.libICE+=		libICE>=0.99.1
BUILDLINK_PKGSRCDIR.libICE?=		../../x11/libICE

.endif # LIBICE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
