# $NetBSD: buildlink3.mk,v 1.1 2008/05/12 13:19:17 jmcneill Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
COMPIZ_FUSION_PLUGINS_MAIN_BUILDLINK3_MK:=	${COMPIZ_FUSION_PLUGINS_MAIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	compiz-fusion-plugins-main
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ncompiz-fusion-plugins-main}
BUILDLINK_PACKAGES+=	compiz-fusion-plugins-main
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}compiz-fusion-plugins-main

.if ${COMPIZ_FUSION_PLUGINS_MAIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.compiz-fusion-plugins-main+=	compiz-fusion-plugins-main>=0.6.0nb1
BUILDLINK_PKGSRCDIR.compiz-fusion-plugins-main?=	../../wm/compiz-fusion-plugins-main
.endif	# COMPIZ_FUSION_PLUGINS_MAIN_BUILDLINK3_MK

.include "../../wm/compiz/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
