# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/14 17:34:25 jmmv Exp $
#
# This Makefile fragment is included by packages that use libxklavier.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXKLAVIER_BUILDLINK3_MK:=	${LIBXKLAVIER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxklavier
.endif

.if !empty(LIBXKLAVIER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libxklavier
BUILDLINK_DEPENDS.libxklavier?=		libxklavier>=0.97
BUILDLINK_PKGSRCDIR.libxklavier?=	../../x11/libxklavier

.include "../../textproc/libxml2/buildlink3.mk"

.endif # LIBXKLAVIER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
