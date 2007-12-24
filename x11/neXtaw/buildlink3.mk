# $NetBSD: buildlink3.mk,v 1.12 2007/12/24 18:57:49 bjs Exp $

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

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
.PHONY: buildlink-neXtaw-inc-hack
buildlink-neXtaw-cookie: buildlink-neXtaw-inc-hack
 
buildlink-neXtaw-inc-hack: buildlink-directories
	[ ! -h ${BUILDLINK_DIR}/include/X11/Xaw ] && \
		${MKDIR} ${BUILDLINK_DIR}/include/X11 && \
		${LN} -s neXtaw ${BUILDLINK_DIR}/include/X11/Xaw
.endif
.endif	# NEXTAW_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

LIBXAW?=	-L${BUILDLINK_PREFIX.neXtaw}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.neXtaw}/lib	\
		-lneXtaw

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
