# $NetBSD: buildlink3.mk,v 1.6 2019/03/11 06:54:09 wiz Exp $

BUILDLINK_TREE+=	libXcomposite

.include "../../mk/bsd.fast.prefs.mk"

.if !defined(LIBXCOMPOSITE_BUILDLINK3_MK)
LIBXCOMPOSITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXcomposite+=	libXcomposite>=0.3.1
BUILDLINK_PKGSRCDIR.libXcomposite?=	../../x11/libXcomposite

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.endif # LIBXCOMPOSITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXcomposite
