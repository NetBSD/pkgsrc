# $NetBSD: buildlink3.mk,v 1.11 2007/02/08 00:08:20 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XAW3D_BUILDLINK3_MK:=	${XAW3D_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Xaw3d
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NXaw3d}
BUILDLINK_PACKAGES+=	Xaw3d
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Xaw3d

.if !empty(XAW3D_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.Xaw3d+=	Xaw3d>=1.5
BUILDLINK_ABI_DEPENDS.Xaw3d?=	Xaw3d>=1.5Enb1
BUILDLINK_PKGSRCDIR.Xaw3d?=	../../x11/Xaw3d

BUILDLINK_TRANSFORM+=		l:Xaw:Xaw3d

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
.PHONY: buildlink-Xaw3d-inc-hack
buildlink-Xaw3d-cookie: buildlink-Xaw3d-inc-hack

buildlink-Xaw3d-inc-hack: buildlink-directories
	[ ! -h ${BUILDLINK_DIR}/include/X11/Xaw ] && \
		${MKDIR} ${BUILDLINK_DIR}/include/X11 && \
		${LN} -s Xaw3d ${BUILDLINK_DIR}/include/X11/Xaw
.endif
.endif	# XAW3D_BUILDLINK3_MK

.include "../../x11/libXmu/buildlink3.mk"

LIBXAW?=	-L${BUILDLINK_PREFIX.Xaw3d}/lib				\
		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.Xaw3d}/lib	\
		-lXaw3d

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
