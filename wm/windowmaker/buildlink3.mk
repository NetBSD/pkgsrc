# $NetBSD: buildlink3.mk,v 1.41 2023/01/29 21:15:02 ryoon Exp $

BUILDLINK_TREE+=	windowmaker

.if !defined(WINDOWMAKER_BUILDLINK3_MK)
WINDOWMAKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.windowmaker+=	windowmaker>=0.95.4
BUILDLINK_ABI_DEPENDS.windowmaker+=	windowmaker>=0.95.9nb9
BUILDLINK_PKGSRCDIR.windowmaker?=	../../wm/windowmaker

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # WINDOWMAKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-windowmaker
