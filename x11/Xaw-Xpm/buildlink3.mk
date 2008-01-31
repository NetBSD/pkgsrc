# $NetBSD: buildlink3.mk,v 1.13 2008/01/31 13:08:12 rillig Exp $

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

.  if ${X11_TYPE} == "modular"
buildlink-Xaw-Xpm-cookie: .PHONY buildlink-Xaw-Xpm-inc-hack

buildlink-Xaw-Xpm-inc-hack: .PHONY buildlink-directories
	[ ! -h ${BUILDLINK_DIR}/include/X11/Xaw ] && \
		${MKDIR} ${BUILDLINK_DIR}/include/X11 && \
		${LN} -s Xaw3d ${BUILDLINK_DIR}/include/X11/Xaw
.  endif

LIBXAW?=	-L${BUILDLINK_PREFIX.Xaw-Xpm}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.Xaw-Xpm}/lib	\
		-L${BUILDLINK_PREFIX.libXpm}/lib			\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libXpm}/lib	\
		-lXaw3d -lXpm

.endif	# XAW_XPM_BUILDLINK3_MK

.include "../../x11/libXpm/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
