# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:18:21 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SABLOTRON_BUILDLINK3_MK:=	${SABLOTRON_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	sablotron
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsablotron}
BUILDLINK_PACKAGES+=	sablotron

.if !empty(SABLOTRON_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.sablotron+=	sablotron>=1.0
BUILDLINK_RECOMMENDED.sablotron+=	sablotron>=1.0.1nb1
BUILDLINK_PKGSRCDIR.sablotron?=	../../textproc/sablotron
.endif	# SABLOTRON_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
