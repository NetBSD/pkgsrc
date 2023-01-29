# $NetBSD: buildlink3.mk,v 1.43 2023/01/29 21:15:02 ryoon Exp $

BUILDLINK_TREE+=	compiz-fusion-plugins-main

.if !defined(COMPIZ_FUSION_PLUGINS_MAIN_BUILDLINK3_MK)
COMPIZ_FUSION_PLUGINS_MAIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compiz-fusion-plugins-main+=	compiz-fusion-plugins-main>=0.6.0nb1
BUILDLINK_ABI_DEPENDS.compiz-fusion-plugins-main+=	compiz-fusion-plugins-main>=0.8.8nb48
BUILDLINK_PKGSRCDIR.compiz-fusion-plugins-main?=	../../wm/compiz-fusion-plugins-main

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"

.endif # COMPIZ_FUSION_PLUGINS_MAIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-compiz-fusion-plugins-main
