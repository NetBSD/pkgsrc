# $NetBSD: buildlink3.mk,v 1.5 2006/04/06 06:22:52 reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XERCES_C_BUILDLINK3_MK:=	${XERCES_C_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xerces-c
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxerces-c}
BUILDLINK_PACKAGES+=	xerces-c

.if !empty(XERCES_C_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xerces-c+=	xerces-c>=2.3.0
BUILDLINK_ABI_DEPENDS.xerces-c?=	xerces-c>=2.3.0nb3
BUILDLINK_PKGSRCDIR.xerces-c?=	../../textproc/xerces-c
.endif	# XERCES_C_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
