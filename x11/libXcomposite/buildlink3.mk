# $NetBSD: buildlink3.mk,v 1.4 2013/12/14 09:36:57 tron Exp $

.include "../../mk/bsd.fast.prefs.mk"

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
