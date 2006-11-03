# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 22:27:45 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXCURSOR_BUILDLINK3_MK:=	${LIBXCURSOR_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXcursor
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXcursor}
BUILDLINK_PACKAGES+=	libXcursor
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXcursor

.if ${LIBXCURSOR_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXcursor+=	libXcursor>=1.1.1
BUILDLINK_PKGSRCDIR.libXcursor?=	../../x11/libXcursor
.endif	# LIBXCURSOR_BUILDLINK3_MK

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
