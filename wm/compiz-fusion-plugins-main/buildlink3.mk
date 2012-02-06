# $NetBSD: buildlink3.mk,v 1.10 2012/02/06 12:41:48 wiz Exp $

BUILDLINK_TREE+=	compiz-fusion-plugins-main

.if !defined(COMPIZ_FUSION_PLUGINS_MAIN_BUILDLINK3_MK)
COMPIZ_FUSION_PLUGINS_MAIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiz-fusion-plugins-main+=	compiz-fusion-plugins-main>=0.6.0nb1
BUILDLINK_ABI_DEPENDS.compiz-fusion-plugins-main?=	compiz-fusion-plugins-main>=0.8.4nb8
BUILDLINK_PKGSRCDIR.compiz-fusion-plugins-main?=	../../wm/compiz-fusion-plugins-main

.include "../../wm/compiz/buildlink3.mk"
.endif # COMPIZ_FUSION_PLUGINS_MAIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiz-fusion-plugins-main
