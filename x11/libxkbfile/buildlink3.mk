# $NetBSD: buildlink3.mk,v 1.3 2006/11/08 13:17:37 joerg Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXKBFILE_BUILDLINK3_MK:=	${LIBXKBFILE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libxkbfile
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxkbfile}
BUILDLINK_PACKAGES+=	libxkbfile
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxkbfile

.if ${LIBXKBFILE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libxkbfile+=	libxkbfile>=0.99.1
BUILDLINK_PKGSRCDIR.libxkbfile?=	../../x11/libxkbfile
.endif	# LIBXKBFILE_BUILDLINK3_MK

.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
