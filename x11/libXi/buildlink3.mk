# $NetBSD: buildlink3.mk,v 1.10 2018/03/07 11:57:36 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && \
    !defined(BUILDLINK_API_DEPENDS.libXi)
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libXi

.  if !defined(LIBXI_BUILDLINK3_MK)
LIBXI_BUILDLINK3_MK:=

.  if !defined(USE_BUILTIN.libXi)
CHECK_BUILTIN.libXi:=	yes
.    include "../../x11/libXi/builtin.mk"
CHECK_BUILTIN.libXi:=	no
.  endif

BUILDLINK_API_DEPENDS.libXi+=	libXi>=1.0.0
BUILDLINK_PKGSRCDIR.libXi?=	../../x11/libXi

.  if !empty(USE_BUILTIN.libXi:M[Nn][Oo])
BUILDLINK_API_DEPENDS.libX11+=		libX11>=1.5
BUILDLINK_API_DEPENDS.libXext+=		libXext>=1.1
.  endif
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.  endif # LIBXI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXi

.endif
