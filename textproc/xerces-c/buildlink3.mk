# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:15 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XERCES_C_BUILDLINK3_MK:=	${XERCES_C_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xerces-c
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxerces-c}
BUILDLINK_PACKAGES+=	xerces-c

.if !empty(XERCES_C_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xerces-c+=	xerces-c>=2.3.0
BUILDLINK_PKGSRCDIR.xerces-c?=	../../textproc/xerces-c
.endif	# XERCES_C_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
