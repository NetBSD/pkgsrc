# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 07:11:28 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libzvt.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBZVT_BUILDLINK3_MK:=	${LIBZVT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libzvt
.endif

.if !empty(LIBZVT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libzvt
BUILDLINK_DEPENDS.libzvt+=		libzvt>=2.0.1nb5
BUILDLINK_PKGSRCDIR.libzvt?=		../../x11/libzvt

.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # LIBZVT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
