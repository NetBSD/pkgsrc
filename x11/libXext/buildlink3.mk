# $NetBSD: buildlink3.mk,v 1.4 2007/02/02 09:21:15 drochner Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXEXT_BUILDLINK3_MK:=	${LIBXEXT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXext
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXext}
BUILDLINK_PACKAGES+=	libXext
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXext

.if ${LIBXEXT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXext+=	libXext>=0.99.0
BUILDLINK_PKGSRCDIR.libXext?=	../../x11/libXext
.endif	# LIBXEXT_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
# XXX don't include xextproto/bl3 here; packages checking for xext.pc must
# include it theirselfes

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
