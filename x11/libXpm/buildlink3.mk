# $NetBSD: buildlink3.mk,v 1.3 2006/12/27 13:37:42 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../graphics/xpm/buildlink3.mk"

BUILDLINK_PREFIX.libXpm=	${BUILDLINK_PREFIX.xpm}
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXPM_BUILDLINK3_MK:=	${LIBXPM_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXpm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXpm}
BUILDLINK_PACKAGES+=	libXpm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXpm

.if ${LIBXPM_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXpm+=	libXpm>=3.5.4.2
BUILDLINK_PKGSRCDIR.libXpm?=	../../x11/libXpm
.endif	# LIBXPM_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
