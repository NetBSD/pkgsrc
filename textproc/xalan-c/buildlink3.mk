# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 04:20:16 minskim Exp $
#
# This Makefile fragment is included by packages that use xalan-c.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XALAN_C_BUILDLINK3_MK:=	${XALAN_C_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xalan-c
.endif

.if !empty(XALAN_C_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			xalan-c
BUILDLINK_DEPENDS.xalan-c+=		xalan-c>=1.6
BUILDLINK_PKGSRCDIR.xalan-c?=		../../textproc/xalan-c

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"

.endif # XALAN_C_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
