# $NetBSD: buildlink3.mk,v 1.16 2012/05/07 01:54:06 dholland Exp $

BUILDLINK_TREE+=	Xaw-Xpm

.if !defined(XAW_XPM_BUILDLINK3_MK)
XAW_XPM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Xaw-Xpm+=	Xaw-Xpm>=1.1
BUILDLINK_ABI_DEPENDS.Xaw-Xpm+=	Xaw-Xpm>=1.1nb2
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

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # XAW_XPM_BUILDLINK3_MK

BUILDLINK_TREE+=	-Xaw-Xpm
