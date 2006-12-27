# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/12/27 12:23:15 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXSCRNSAVER_BUILDLINK3_MK:=	${LIBXSCRNSAVER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXScrnSaver
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXScrnSaver}
BUILDLINK_PACKAGES+=	libXScrnSaver
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXScrnSaver

.if ${LIBXSCRNSAVER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXScrnSaver+=	libXScrnSaver>=1.1.2
BUILDLINK_PKGSRCDIR.libXScrnSaver?=	../../x11/libXScrnSaver
.endif	# LIBXSCRNSAVER_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

.endif
