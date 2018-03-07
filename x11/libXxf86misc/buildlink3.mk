# $NetBSD: buildlink3.mk,v 1.5 2018/03/07 11:57:37 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libXxf86misc

.  if !defined(LIBXXF86MISC_BUILDLINK3_MK)
LIBXXF86MISC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXxf86misc+=	libXxf86misc>=1.0.0
BUILDLINK_PKGSRCDIR.libXxf86misc?=	../../x11/libXxf86misc

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.  endif # LIBXXF86MISC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXxf86misc

.endif
