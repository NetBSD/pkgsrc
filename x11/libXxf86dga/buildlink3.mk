# $NetBSD: buildlink3.mk,v 1.4 2018/03/07 11:57:37 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libXxf86dga

.  if !defined(LIBXXF86DGA_BUILDLINK3_MK)
LIBXXF86DGA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXxf86dga+=	libXxf86dga>=1.0.1
BUILDLINK_PKGSRCDIR.libXxf86dga?=	../../x11/libXxf86dga

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.  endif # LIBXXF86DGA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXxf86dga

.endif
