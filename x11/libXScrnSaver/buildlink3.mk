# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:43 joerg Exp $

BUILDLINK_TREE+=	libXScrnSaver

.if !defined(LIBXSCRNSAVER_BUILDLINK3_MK)
LIBXSCRNSAVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXScrnSaver+=	libXScrnSaver>=1.1.2
BUILDLINK_PKGSRCDIR.libXScrnSaver?=	../../x11/libXScrnSaver

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.endif # LIBXSCRNSAVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXScrnSaver
