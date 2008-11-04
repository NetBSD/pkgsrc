# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/04 10:35:22 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RASQAL_BUILDLINK3_MK:=	${RASQAL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	rasqal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nrasqal}
BUILDLINK_PACKAGES+=	rasqal
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}rasqal

.if ${RASQAL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.rasqal+=	rasqal>=0.9.14
BUILDLINK_ABI_DEPENDS.rasqal?=	rasqal>=0.9.14nb1
BUILDLINK_PKGSRCDIR.rasqal?=	../../textproc/rasqal
.endif	# RASQAL_BUILDLINK3_MK

.include "../../textproc/raptor/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
