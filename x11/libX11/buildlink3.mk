# $NetBSD: buildlink3.mk,v 1.3 2007/01/02 11:35:13 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBX11_BUILDLINK3_MK:=	${LIBX11_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libX11
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibX11}
BUILDLINK_PACKAGES+=	libX11
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libX11

.if ${LIBX11_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=0.99
BUILDLINK_PKGSRCDIR.libX11?=	../../x11/libX11

X11_LDFLAGS+=	${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
X11_LDFLAGS+=	-L${BUILDLINK_PREFIX.libX11}/lib
.endif	# LIBX11_BUILDLINK3_MK

.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
