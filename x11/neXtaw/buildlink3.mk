# $NetBSD: buildlink3.mk,v 1.11 2007/01/30 21:00:31 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NEXTAW_BUILDLINK3_MK:=	${NEXTAW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	neXtaw
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NneXtaw}
BUILDLINK_PACKAGES+=	neXtaw
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}neXtaw

.if !empty(NEXTAW_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.neXtaw+=	neXtaw>=0.15.1
BUILDLINK_ABI_DEPENDS.neXtaw+=	neXtaw>=0.15.1nb2
BUILDLINK_PKGSRCDIR.neXtaw?=	../../x11/neXtaw
.endif	# NEXTAW_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

LIBXAW?=	-L${BUILDLINK_PREFIX.neXtaw}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.neXtaw}/lib	\
		-lneXtaw

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
