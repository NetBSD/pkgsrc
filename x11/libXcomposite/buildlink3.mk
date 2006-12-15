# $NetBSD: buildlink3.mk,v 1.2 2006/12/15 20:16:18 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../x11/Xcomposite/buildlink3.mk"
.else

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXCOMPOSITE_BUILDLINK3_MK:=	${LIBXCOMPOSITE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXcomposite
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXcomposite}
BUILDLINK_PACKAGES+=	libXcomposite
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXcomposite

.if ${LIBXCOMPOSITE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXcomposite+=	libXcomposite>=0.3.1
BUILDLINK_PKGSRCDIR.libXcomposite?=	../../x11/libXcomposite
.endif	# LIBXCOMPOSITE_BUILDLINK3_MK

.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.endif
