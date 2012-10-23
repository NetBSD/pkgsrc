# $NetBSD: buildlink3.mk,v 1.6 2012/10/23 10:24:18 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_TREE+=	libXaw

.if !defined(LIBXAW_BUILDLINK3_MK)
LIBXAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXaw+=	libXaw>=1.0.5
BUILDLINK_PKGSRCDIR.libXaw?=	../../x11/libXaw
BUILDLINK_TRANSFORM+=		l:Xaw:Xaw7

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # LIBXAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXaw

.endif
