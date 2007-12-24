# $NetBSD: buildlink3.mk,v 1.12 2007/12/24 18:57:49 bjs Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XAW_XPM_BUILDLINK3_MK:=	${XAW_XPM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xaw-Xpm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXaw-Xpm}
BUILDLINK_PACKAGES+=	Xaw-Xpm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Xaw-Xpm

.if !empty(XAW_XPM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Xaw-Xpm+=	Xaw-Xpm>=1.1
BUILDLINK_ABI_DEPENDS.Xaw-Xpm?=	Xaw-Xpm>=1.1nb2
BUILDLINK_PKGSRCDIR.Xaw-Xpm?=	../../x11/Xaw-Xpm

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
.PHONY: buildlink-Xaw_Xpm-inc-hack
buildlink-Xaw-Xpm-cookie: buildlink-Xaw-Xpm-inc-hack

buildlink-Xaw-Xpm-inc-hack: buildlink-directories
	[ ! -h ${BUILDLINK_DIR}/include/X11/Xaw ] && \
		${MKDIR} ${BUILDLINK_DIR}/include/X11 && \
		${LN} -s Xaw3d ${BUILDLINK_DIR}/include/X11/Xaw
.endif
.endif	# XAW_XPM_BUILDLINK3_MK

.include "../../x11/libXpm/buildlink3.mk"

LIBXAW?=	-L${BUILDLINK_PREFIX.Xaw-Xpm}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.Xaw-Xpm}/lib	\
		-L${BUILDLINK_PREFIX.libXpm}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libXpm}/lib	\
		-lXaw3d -lXpm

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
