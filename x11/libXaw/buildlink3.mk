# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/11/03 21:12:55 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXAW_BUILDLINK3_MK:=	${LIBXAW_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libXaw
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXaw}
BUILDLINK_PACKAGES+=	libXaw
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libXaw

.if ${LIBXAW_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libXaw+=	libXaw>=1.0.1
BUILDLINK_PKGSRCDIR.libXaw?=	../../x11/libXaw
BUILDLINK_TRANSFORM+=		l:Xaw:Xaw8
.endif	# LIBXAW_BUILDLINK3_MK

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
