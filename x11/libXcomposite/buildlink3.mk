# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:44 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../x11/Xcomposite/buildlink3.mk"
.else

BUILDLINK_TREE+=	libXcomposite

.if !defined(LIBXCOMPOSITE_BUILDLINK3_MK)
LIBXCOMPOSITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXcomposite+=	libXcomposite>=0.3.1
BUILDLINK_PKGSRCDIR.libXcomposite?=	../../x11/libXcomposite

.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.endif # LIBXCOMPOSITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXcomposite

.endif
