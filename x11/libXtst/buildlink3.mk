# $NetBSD: buildlink3.mk,v 1.2 2006/12/17 18:05:13 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular"
.include "../../mk/x11.buildlink3.mk"
.else


BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXTST_BUILDLINK3_MK:=	${LIBXTST_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXtst
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXtst}
BUILDLINK_PACKAGES+=	libXtst
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXtst

.if ${LIBXTST_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXtst+=	libXtst>=1.0.1
BUILDLINK_PKGSRCDIR.libXtst?=	../../x11/libXtst
.endif	# LIBXTST_BUILDLINK3_MK

.include "../../x11/recordproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.endif
