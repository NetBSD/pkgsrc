# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:41 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XALAN_C_BUILDLINK3_MK:=	${XALAN_C_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xalan-c
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxalan-c}
BUILDLINK_PACKAGES+=	xalan-c

.if !empty(XALAN_C_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xalan-c+=	xalan-c>=1.6
BUILDLINK_PKGSRCDIR.xalan-c?=	../../textproc/xalan-c

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"

.endif	# XALAN_C_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
